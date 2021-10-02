/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:40:18 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/16 08:10:01 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	zero_fill(unsigned long num, t_data table)
{
	while (table->width && table->width > (table->output))
	{
		if (table->period && !(table->precision))
		{
			table->count += write(1, " ", 1);
			(table->width)--;
		}
		else
		{
			table->count += write(1, "0", 1);
			(table->width)--;
		}
	}
	ft_putnbr_base(num, HEXLOW, table);
}

void	handle_x(t_data table)
{
	unsigned int	num;
	unsigned int	x;

	num = va_arg(table->ap, unsigned int);
	x = num;
	if (num == 0)
		(table->output) = 1;
	while (x != 0)
	{
		x /= 16;
		(table->output)++;
	}
	if (table->period && !(table->precision) && num == 0)
		table->output = 0;
	if (table->zero && !((table->precision) > 0) && !(table->dash))
		zero_fill(num, table);
	else
		handle_spec_x(num, table);
	(table->i)++;
	reset_table(table);
}
