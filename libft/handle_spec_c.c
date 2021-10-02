/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spec_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:29:32 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/16 08:09:13 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	dashprecision(t_data table)
{
	while (table->precision && table->precision > table->output)
	{
		table->c = '0';
		table->count += write(1, &(table->c), 1);
		(table->output)++;
	}
	table->count += write(1, &(table->cha), 1);
	while (table->width && table->width > (table->output))
	{
		table->c = ' ';
		table->count += write(1, &(table->c), 1);
		(table->width)--;
	}
}

static void	dashnotprecision(t_data table)
{
	table->count += write(1, &(table->cha), 1);
	while (table->width && table->width > table->output)
	{
		table->c = ' ';
		table->count += write(1, &(table->c), 1);
		(table->width)--;
	}
}

static void	notdashprecision(t_data table)
{
	if (table->precision > table->output)
		(table->width) -= table->output;
	if (table->precision < table->width)
	{
		while (table->width && table->width > (table->output))
		{
			table->c = ' ';
			table->count += write(1, &(table->c), 1);
			(table->width)--;
		}
	}
	while (table->precision && table->precision > table->output)
	{
		table->c = '0';
		table->count += write(1, &(table->c), 1);
		(table->precision)--;
	}
	table->count += write(1, &(table->cha), 1);
}

static void	notdashnotprecision(t_data table)
{
	while (table->width && table->width > table->output)
	{
		table->c = ' ';
		table->count += write(1, &(table->c), 1);
		(table->width)--;
	}
	table->count += write(1, &(table->cha), 1);
}

void	handle_spec_c(t_data table)
{
	if (table->dash && table->precision)
		dashprecision(table);
	if (table->dash && !(table->precision))
		dashnotprecision(table);
	if (!(table->dash) && table->precision)
		notdashprecision(table);
	if (!(table->dash) && !(table->precision))
		notdashnotprecision(table);
}
