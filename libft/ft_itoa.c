/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:52:54 by ioleinik          #+#    #+#             */
/*   Updated: 2021/05/17 15:52:30 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len(int n)
{
	size_t	size;

	size = 0;
	if (n <= 0)
		size = 1;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	size_t	size;

	size = len(n);
	str = (char *)malloc(size + 1);
	if (NULL == str)
		return (str);
	num = n;
	if (n < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (n == 0)
		str[0] = '0';
	str[size] = '\0';
	while (num != 0)
	{
		str[size - 1] = (num % 10) + '0';
		num /= 10;
		size--;
	}
	return (str);
}
