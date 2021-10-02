/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 07:50:09 by ioleinik          #+#    #+#             */
/*   Updated: 2021/07/23 15:28:40 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	char	*dup;
	size_t	l;

	if (!src)
		return (NULL);
	l = 0;
	while (src[l] != '\0')
		l++;
	dup = (char *)malloc(sizeof(char) * (l + 1));
	if (NULL == dup)
		return (dup);
	i = 0;
	while (i < l)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
