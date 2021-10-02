/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:35:25 by ioleinik          #+#    #+#             */
/*   Updated: 2021/05/20 12:32:40 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	x;

	x = n;
	if (x < 0)
	{
		x = x * (-1);
		ft_putchar_fd('-', fd);
	}
	if (x >= 10)
	{
		ft_putnbr_fd(x / 10, fd);
		ft_putnbr_fd(x % 10, fd);
	}
	else
	{
		ft_putchar_fd(x + '0', fd);
	}
}
