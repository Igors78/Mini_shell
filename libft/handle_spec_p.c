/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spec_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:29:32 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/16 08:09:23 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	dashprecision(unsigned long num, t_data table)
{
	while (table->precision && table->precision > table->output)
	{
		table->count += write(1, "0", 1);
		(table->output)++;
	}
	if (0 == num)
		table->count += write(1, "0x0", 3);
	else
	{
		table->count += write(1, "0x", 2);
		ft_putnbr_base(num, HEXLOW, table);
	}
	while (table->width && table->width > (table->output))
	{
		table->c = ' ';
		table->count += write(1, &(table->c), 1);
		(table->width)--;
	}
}

static void	dashnotprecision(unsigned long num, t_data table)
{
	if (0 == num)
		table->count += write(1, "0x0", 3);
	else
	{
		table->count += write(1, "0x", 2);
		ft_putnbr_base(num, HEXLOW, table);
	}
	while (table->width && table->width > table->output)
	{
		table->c = ' ';
		table->count += write(1, &(table->c), 1);
		(table->width)--;
	}
}

static void	notdashprecision(unsigned long num, t_data table)
{
	handle_precis(num, table);
	while (table->precision && table->precision > table->output)
	{
		table->count += write(1, "0", 1);
		(table->precision)--;
	}
	if (0 == num)
		table->count += write(1, "0x0", 3);
	else
	{
		table->count += write(1, "0x", 2);
		ft_putnbr_base(num, HEXLOW, table);
	}
}

static void	notdashnotprecision(unsigned long num, t_data table)
{
	while (table->width && table->width > table->output)
	{
		table->c = ' ';
		table->count += write(1, &(table->c), 1);
		(table->width)--;
	}
	if (0 == num)
		table->count += write(1, "0x0", 3);
	else
	{
		table->count += write(1, "0x", 2);
		ft_putnbr_base(num, HEXLOW, table);
	}
}

void	handle_spec_p(unsigned long num, t_data table)
{
	if (table->dash && table->precision)
		dashprecision(num, table);
	if (table->dash && !(table->precision))
		dashnotprecision(num, table);
	if (!(table->dash) && table->precision)
		notdashprecision(num, table);
	if (!(table->dash) && !(table->precision))
		notdashnotprecision(num, table);
}
