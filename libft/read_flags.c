/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 09:25:31 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/16 08:20:24 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	handle_asterisk(t_data table)
{
	if (table->period)
	{
		table->precision = va_arg(table->ap, int);
	}
	else
	{
		table->width = va_arg(table->ap, int);
		if (table->width < 0)
		{
			(table->width) *= -1;
			table->dash = 1;
			table->zero = 0;
		}
	}
	(table->i)++;
}

static void	handle_nums(char *format, t_data table)
{
	int	res;

	res = 0;
	while (ft_strchr(NUMS, format[table->i]))
	{
		res = res * 10 + (format[table->i] - '0');
		(table->i)++;
	}
	if (table->period)
		table->precision = res;
	else
		table->width = res;
}

void	read_flags(char *format, t_data table)
{
	while (ft_strchr(FLAGS, format[table->i])
		|| ft_strchr(NUMS, format[table->i]))
	{
		if (format[table->i] == '-')
		{
			table->dash = 1;
			(table->i)++;
		}
		if (format[table->i] == '0')
		{
			table->zero = 1;
			(table->i)++;
		}
		if (format[table->i] == '.')
		{
			table->period = 1;
			(table->i)++;
		}
		if (format[table->i] == '*')
			handle_asterisk(table);
		if (ft_strchr(NUMS, format[table->i]))
			handle_nums(format, table);
	}
}
