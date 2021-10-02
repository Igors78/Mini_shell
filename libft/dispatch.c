/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:26:03 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/16 08:07:45 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dispatch(char *format, t_data table)
{
	if (format[table->i] == 'd' || format[(table->i)] == 'i')
		handle_d(table);
	else if (format[(table->i)] == 'c')
		handle_c(table);
	else if (format[(table->i)] == 's')
	{
		handle_s(table);
		reset_table(table);
	}
	else if (format[(table->i)] == 'p')
		handle_p(table);
	else if (format[(table->i)] == 'u')
		handle_u(table);
	else if (format[(table->i)] == 'x')
		handle_x(table);
	else if (format[(table->i)] == 'X')
		handle_bigx(table);
	else if (format[(table->i)] == '%')
		handle_perc(format, table);
	else
	{
		table->c = format[table->i];
		table->count += write(1, &(table->c), 1);
		(table->i)++;
	}
}
