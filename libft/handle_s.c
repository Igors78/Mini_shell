/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:44:45 by ioleinik          #+#    #+#             */
/*   Updated: 2021/06/16 08:08:56 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnul(char *s, t_data table)
{
	if (!s)
	{
		if (table->period && (table->precision < 6) && (table->precision > 0))
		{
			table->output = 0;
			return ;
		}
		table->count += write(1, "(null)", 6);
		return ;
	}
}

static void	putstr(char *s, t_data table)
{
	int		x;

	x = 0;
	putnul(s, table);
	if (s && table->precision)
	{
		while (s[x] != '\0' && x < table->precision)
		{
			table->count += write(1, &(s[x]), 1);
			x++;
		}
	}
	else
	{
		while (s && s[x] != '\0')
		{
			table->count += write(1, &(s[x]), 1);
			x++;
		}
	}
}

static void	notdash(char *s, t_data table)
{
	if (!(table->dash))
	{
		if (table->precision < 0)
			table->precision = 0;
		if (!s && (table->precision) && !(table->precision >= table->output))
			(table->width)++;
		if (table->width > table->precision && table->precision
			&& table->precision < table->output)
			table->output = table->precision;
		while (table->width && table->width > table->output)
		{
			table->c = ' ';
			table->count += write(1, &(table->c), 1);
			(table->width)--;
		}
		putstr(s, table);
	}
}

static void	dash(char *s, t_data table)
{
	if (table->precision < 0)
		table->precision = 0;
	if (table->dash)
	{
		putstr(s, table);
		if (!s && (table->precision) && !(table->precision >= table->output))
			(table->width)++;
		if (table->width > table->precision && table->precision
			&& table->precision < table->output)
			table->output = table->precision;
		while ((table->width) && table->width > table->output)
		{
			table->count += write(1, " ", 1);
			(table->width)--;
		}
		if (table->width < table->precision && s)
			return ;
		while (table->width > 1 && table->width < table->output
			&& table->width < table->precision
			&& table->precision < table->output)
		{
			table->count += write(1, " ", 1);
			(table->width)--;
		}
	}
}

void	handle_s(t_data table)
{
	char		*s;

	s = (char *)va_arg(table->ap, char *);
	while (s && s[table->output] != '\0')
		(table->output)++;
	if (!s)
		table->output = 6;
	if ((table->period) && !(table->precision))
	{
		while ((table->width))
		{
			table->count += write(1, " ", 1);
			(table->width)--;
		}
	}
	else
	{
		notdash(s, table);
		dash(s, table);
	}
	(table->i)++;
}
