/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:35:45 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/16 08:08:32 by ioleinik         ###   ########.fr       */
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
	ft_putnbr_base(num, DEC, table);
}

void	handle_p(t_data table)
{
	unsigned long	num;
	unsigned long	x;

	num = (unsigned long)va_arg(table->ap, unsigned long);
	x = num;
	if (0 == num)
		table->output = 3;
	else
		table->output = 2;
	while (x != 0)
	{
		x /= 16;
		(table->output)++;
	}
	if (table->zero && !((table->precision) > 0) && !(table->dash))
		zero_fill(num, table);
	else
		handle_spec_p(num, table);
	(table->i)++;
	reset_table(table);
}
