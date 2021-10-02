/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:13:52 by ioleinik          #+#    #+#             */
/*   Updated: 2021/05/22 13:53:10 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	ret;
	char	*s;

	s = (char *)src;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(s);
	i = 0;
	ret = 0;
	if (size > dest_len)
		ret = src_len + dest_len;
	else
		ret = src_len + size;
	while (s[i] != '\0' && dest_len + 1 < size)
	{
		dest[dest_len] = s[i];
		i++;
		dest_len++;
	}
	dest[dest_len] = '\0';
	return (ret);
}
