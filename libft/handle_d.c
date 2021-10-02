/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:39:17 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/16 08:08:24 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_minus(long *num, t_data table)
{
	if ((*num) < 0)
	{
		table->count += write(1, "-", 1);
		*num = (*num) * (-1);
	}
}

static void	zero_fill(long num, t_data table)
{
	if (table->period && !(table->precision))
	{
		while (table->width && table->width > (table->output))
		{
			table->count += write(1, " ", 1);
			(table->width)--;
		}
		put_minus(&num, table);
		ft_putnbr_base(num, DEC, table);
	}
	else
	{
		put_minus(&num, table);
		while (table->width && table->width > (table->output))
		{
			table->count += write(1, "0", 1);
			(table->width)--;
		}
		ft_putnbr_base(num, DEC, table);
	}
}

void	handle_d(t_data table)
{
	long int	num;
	long int	x;

	num = va_arg(table->ap, int);
	x = num;
	if (x <= 0)
		table->output = 1;
	if (table->period && !(table->precision) && num == 0)
		table->output = 0;
	while (x != 0)
	{
		x /= 10;
		(table->output)++;
	}
	if (table->zero && !((table->precision) > 0) && !(table->dash))
		zero_fill(num, table);
	else
		handle_spec(num, table);
	(table->i)++;
	reset_table(table);
}
