/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 22:25:55 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/16 08:19:08 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	conversion(long nbr, char *base, t_data table)
{
	long	x;
	int		baza;

	x = nbr;
	baza = ft_strlen(base);
	if (x < 0)
	{
		x = x * (-1);
		table->c = '-';
		table->count += write(1, &(table->c), 1);
	}
	if (x >= baza)
	{
		conversion(x / baza, base, table);
		conversion(x % baza, base, table);
	}
	else
	{
		table->c = base[x];
		table->count += write(1, &(table->c), 1);
	}
}

void	ft_putnbr_base(long nbr, char *base, t_data table)
{
	if (table->period && !(table->precision) && nbr == 0)
		return ;
	conversion(nbr, base, table);
}
