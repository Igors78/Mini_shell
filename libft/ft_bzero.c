/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 22:01:56 by ioleinik          #+#    #+#             */
/*   Updated: 2021/05/12 07:18:50 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_bzero(void *str, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		((char *)str)[i] = '\0';
		i++;
	}
}
