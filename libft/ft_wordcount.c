/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 12:53:28 by ioleinik          #+#    #+#             */
/*   Updated: 2021/07/19 12:54:54 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	if (!s[0])
		return (0);
	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}
