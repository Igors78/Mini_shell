/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:24:40 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/23 10:51:32 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*stick_back(char **spl, char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	free (s);
	s = ft_strdup("\"");
	while (spl[i])
	{
		tmp = ft_strjoin(s, spl[i]);
		free (s);
		s = ft_strdup(tmp);
		free(tmp);
		if (i != (ft_strarrlen(spl) - 1))
		{
			tmp = ft_strjoin(s, " ");
			free (s);
			s = ft_strdup(tmp);
			free(tmp);
		}
		i++;
	}
	tmp = ft_strjoin(s, "\"");
	free (s);
	return (tmp);
}

static char	*expand_dbl_quot(t_data *d, char *s)
{
	int		i;
	char	**spl;

	i = 0;
	s[ft_strlen(s) - 1] = '\0';
	spl = ft_split(&s[1], ' ');
	while (spl[i])
	{
		chk_sing_quo(d, spl, &i);
		chk_curl_br(d, spl, &i);
		i++;
	}
	//put_strarr(spl);
	s = stick_back(spl, s);
	return (s);
}

char	*check_env(t_data *d, char *s)
{
	if (!s)
		return (NULL);
	if (s[0] == '\'' && s[ft_strlen(s) - 1] == '\'')
		return (s);
	else if (s[0] == '\"' && s[ft_strlen(s) - 1] == '\"')
		s = expand_dbl_quot(d, s);
	else if (ft_strchr(s, '$'))
		s = parse_env(d, s);
	return (s);
}
