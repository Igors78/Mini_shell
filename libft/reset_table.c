/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 09:12:54 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/16 08:10:40 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_data	reset_table(t_data table)
{
	table->dash = 0;
	table->zero = 0;
	table->period = 0;
	table->asterisk = 0;
	table->width = 0;
	table->output = 0;
	table->precision = 0;
	return (table);
}
