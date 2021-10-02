/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_perc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 18:26:02 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/16 08:08:39 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_perc(char *format, t_data table)
{
	while (format[table->i] == ' ')
		(table->i)++;
	table->count += write(1, "%", 1);
	(table->i)++;
	reset_table(table);
}
