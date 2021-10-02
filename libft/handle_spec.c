/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:29:32 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/16 08:09:46 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	dashprecision(long num, t_data table)
{
	if (num < 0)
	{
		num = num * (-1);
		table->count += write(1, "-", 1);
		(table->output)--;
		(table->width)--;
	}
	while (table->precision && table->precision > table->output)
	{
		table->count += write(1, "0", 1);
		(table->output)++;
	}
	ft_putnbr_base(num, DEC, table);
	while (table->width && table->width > (table->output))
	{
		table->c = ' ';
		table->count += write(1, &(table->c), 1);
		(table->width)--;
	}
}

static void	dashnotprecision(long num, t_data table)
{
	ft_putnbr_base(num, DEC, table);
	while (table->width && table->width > table->output)
	{
		table->c = ' ';
		table->count += write(1, &(table->c), 1);
		(table->width)--;
	}
}

static void	notdashprecision(long num, t_data table)
{
	handle_precis(num, table);
	if (num < 0)
	{
		num = -num;
		table->count += write(1, "-", 1);
		if (table->precision > (table->output))
			(table->output)--;
		if (table->precision == (table->output))
			(table->precision)++;
	}
	while (table->precision && table->precision > table->output)
	{
		table->count += write(1, "0", 1);
		(table->precision)--;
	}
	ft_putnbr_base(num, DEC, table);
}

static void	notdashnotprecision(long num, t_data table)
{
	while (table->width && table->width > table->output)
	{
		table->c = ' ';
		table->count += write(1, &(table->c), 1);
		(table->width)--;
	}
	ft_putnbr_base(num, DEC, table);
}

void	handle_spec(long num, t_data table)
{
	if (table->dash && table->precision)
		dashprecision(num, table);
	if (table->dash && !(table->precision))
		dashnotprecision(num, table);
	if (!(table->dash) && table->precision)
	{
		notdashprecision(num, table);
		return ;
	}
	if (!(table->dash) && !(table->precision))
		notdashnotprecision(num, table);
}
