/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:29:14 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/16 08:08:15 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	handle_c(t_data table)
{
	table->cha = (char)va_arg(table->ap, int);
	table->output = 1;
	handle_spec_c(table);
	(table->i)++;
	reset_table(table);
}
