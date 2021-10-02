/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 10:55:54 by ioleinik          #+#    #+#             */
/*   Updated: 2021/05/16 12:54:14 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		k;
	char	*p;

	i = 0;
	k = 0;
	p = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (NULL == p)
		return (p);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		p[i] = s2[k];
		i++;
		k++;
	}
	p[i] = '\0';
	return (p);
}
