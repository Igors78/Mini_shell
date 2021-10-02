/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:15:34 by ioleinik          #+#    #+#             */
/*   Updated: 2021/05/22 19:02:41 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	k;

	if (!s1 || !set)
		return (0);
	i = ft_strlen((char *)s1);
	k = 0;
	while (i && ft_strchr(set, s1[i]))
		i--;
	while (s1[k] && ft_strchr(set, s1[k]))
		k++;
	if (k > i)
		return (ft_substr(s1, 0, 0));
	return (ft_substr(s1, k, i - k + 1));
}
