/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:22:48 by ioleinik          #+#    #+#             */
/*   Updated: 2021/05/22 15:32:19 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (to_find[0] == '\0')
	{
		return ((char *)str);
	}
	while (str[i] != '\0' && i < len)
	{
		k = 0;
		while (str[i + k] == to_find[k] && (i + k) < len)
		{
			k++;
			if (to_find[k] == '\0')
			{
				return ((char *)&str[i]);
			}
		}
		i++;
	}
	return (0);
}
