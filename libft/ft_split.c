/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 22:41:12 by ioleinik          #+#    #+#             */
/*   Updated: 2021/05/23 12:04:39 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_str(char const *s, char c)
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

static void	get_next(char **next_str, size_t *next_len, char c)
{
	size_t	i;

	*next_str += *next_len;
	*next_len = 0;
	i = 0;
	while ((*next_str)[i] == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	char	*next_str;
	size_t	next_len;
	size_t	i;

	str_arr = (char **)malloc(sizeof(char *) * (count_str(s, c) + 1));
	if (NULL == str_arr)
		return (str_arr);
	i = 0;
	next_str = (char *)s;
	next_len = 0;
	while (i < count_str(s, c))
	{
		get_next(&next_str, &next_len, c);
		str_arr[i] = (char *)malloc(sizeof(char) * (next_len + 1));
		if (NULL == str_arr[i])
			return (NULL);
		ft_strlcpy(str_arr[i], next_str, next_len + 1);
		i++;
	}
	str_arr[i] = NULL;
	return (str_arr);
}
