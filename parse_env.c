/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 10:47:11 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/24 22:53:14 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*expan_doll(t_data *d, char *s)
{
	char	*beg;
	char	*tmp;

	beg = ft_strdup(s);
	*(ft_strchr(beg, '$')) = '\0';
	tmp = ft_strjoin(beg, parse_env(d, ft_strchr(s, '$')));
	free(beg);
	return (tmp);
}

char	*parse_env(t_data *d, char *s)
{
	char	*tmp;

	if (s[0] == '$')
	{
		if (s[1] == '{' && s[ft_strlen(s) - 1] == '}')
		{
			if (s[2] == '?' && !s[3])
				return (tmp = ft_itoa(d->exit_status));
			s[ft_strlen(s) - 1] = '\0';
			tmp = ft_getenv(d, &s[2]);
		}
		else if (s[1] == '?' && !s[2])
			return (tmp = ft_itoa(d->exit_status));
		else
			tmp = ft_getenv(d, &s[1]);
		if (!tmp)
			return (s = ft_strdup(""));
		return (tmp);
	}
	else
	{
		if (!(ft_strchr(s, '$')))
			return (s);
		return (expan_doll(d, s));
	}
}
