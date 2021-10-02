/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 08:15:25 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/16 08:08:47 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_precis(long num, t_data table)
{
	if (num < 0 && table->precision >= table->output)
		(table->width)--;
	if (table->precision > table->output)
	{
		while (table->width && table->width > (table->precision))
		{
			table->count += write(1, " ", 1);
			(table->width)--;
		}
	}
	else
	{
		if (num < 0)
		{
			(table->output)--;
			(table->precision)--;
		}
		if (num < 0 && table->width > (table->output))
			(table->width)--;
		while (table->width && table->width > (table->output))
		{
			table->count += write(1, " ", 1);
			(table->width)--;
		}
	}
}
