/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:52:28 by ioleinik          #+#    #+#             */
/*   Updated: 2021/05/13 14:25:48 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(const char *str, int ch)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (((unsigned char *)str)[i] == (unsigned char)ch)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == '\0' && (unsigned char)ch == '\0')
		return ((char *)(str + i));
	return (NULL);
}
