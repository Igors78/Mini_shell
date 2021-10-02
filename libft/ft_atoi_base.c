/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:12:56 by ioleinik          #+#    #+#             */
/*   Updated: 2021/07/27 10:18:56 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_base(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i] != c)
		i++;
	if (base[i] == '\0')
		return (0);
	else
		return (1);
}

static int	ft_get_int_from_base(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (i);
}

static int	skip_whitespace_minus(char *str, int *ptr_i)
{
	int		minus_count;
	int		i;

	i = 0;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == ' '
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
		i++;
	minus_count = 0;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			minus_count++;
		i++;
	}
	*ptr_i = i;
	return (minus_count);
}

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	int		result;
	int		base_divider;

	i = 0;
	while (base[i])
		i++;
	base_divider = i;
	result = 0;
	sign = 1;
	if (skip_whitespace_minus(str, &i) % 2)
		sign = -1;
	while (str[i] && ft_is_in_base(str[i], base))
	{
		result *= base_divider;
		result += ft_get_int_from_base(str[i], base);
		i++;
	}
	result *= sign;
	return (result);
}
