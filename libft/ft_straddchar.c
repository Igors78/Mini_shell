/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:06:06 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/27 13:20:38 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_straddchar(char *str, char c)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!str || !c)
		return (NULL);
	res = ft_strnew(ft_strlen(str) + 2);
	if (!res)
		return (NULL);
	while (i < ft_strlen(str))
	{
		res[i] = str[i];
		i++;
	}
	res[i] = c;
	i++;
	res[i] = '\0';
	free(str);
	return (res);
}
