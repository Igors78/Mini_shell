/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 09:17:04 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/16 08:10:21 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	parse(char *format, t_data table)
{
	while (format[table->i] != '\0')
	{
		if (format[table->i] == '%')
		{
			(table->i)++;
			if (format[table->i] != '%' && format[table->i] != ' ')
			{
				read_flags((char *)format, table);
				dispatch((char *)format, table);
			}
			else
				handle_perc(format, table);
		}
		else
		{
			table->c = format[table->i];
			table->count += write(1, &(table->c), 1);
			(table->i)++;
		}
	}
}
