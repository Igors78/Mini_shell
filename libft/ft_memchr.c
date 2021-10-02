/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:41:36 by ioleinik          #+#    #+#             */
/*   Updated: 2021/05/12 17:22:42 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *str, int ch, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (((unsigned char *)str)[i] == (unsigned char)ch)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
