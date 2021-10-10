/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 06:52:38 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/10 10:16:59 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarrdup(char **src)
{
	char	**dup;
	int		i;

	i = 0;
	dup = (char **)malloc(sizeof(char *) * (ft_strarrlen(src) + 1));
	while (src[i])
	{
		dup[i] = ft_strdup(src[i]);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}
