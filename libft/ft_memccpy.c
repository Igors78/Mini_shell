/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 08:19:21 by ioleinik          #+#    #+#             */
/*   Updated: 2021/05/12 08:42:21 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memccpy(void *dest, const void *src, int ch, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		if (((unsigned char *)src)[i] == (unsigned char)ch)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
