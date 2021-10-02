/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 09:11:59 by ioleinik          #+#    #+#             */
/*   Updated: 2021/05/22 16:26:31 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	sub = NULL;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (NULL == sub)
		return (sub);
	if (s[start] == '\0')
	{
		sub[i] = '\0';
		return (sub);
	}
	while (i < len && start < ft_strlen((char *)s))
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
