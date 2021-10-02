/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 19:55:57 by ioleinik          #+#    #+#             */
/*   Updated: 2021/05/11 20:27:36 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memset(void *str, int ch, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		((unsigned char *)str)[i] = ch;
		i++;
	}
	return (str);
}
