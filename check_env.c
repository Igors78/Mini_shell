/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:24:40 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/29 18:03:20 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*glue_back(char **spl)
{
	int		i;
	char	*tmp;
	char	*s;

	i = 0;
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

char	*stick_back(char **spl)
{
	int		i;
	char	*tmp;
	char	*s;

	i = 0;
	s = ft_strdup("\'");
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
	tmp = ft_strjoin(s, "\'");
	free (s);
	return (tmp);
}

static char	*expand_dbl_quot(t_data *d, char *s)
{
	char *ret;

	if (s[0] == '\'' && s[ft_strlen(s) - 1] == '\'')
	{
		s[ft_strlen(s) - 1] = '\0';
		ret = chk_sing_quo(d, &s[1]);
	}
	else
		ret = chk_exp(d, s);
	return (ret);
}

char	*check_env(t_data *d, char *s)
{
	char *ret;

	if (!s)
		return (NULL);
	if (!(ft_strchr(s, '$')))
		return (s);
	if (s[0] == '\'' && s[ft_strlen(s) - 1] == '\'')
		return (s);
	else if (s[0] == '\"' && s[ft_strlen(s) - 1] == '\"')
	{
		s[ft_strlen(s) - 1] = '\0';
		ret = expand_dbl_quot(d, &s[1]);
		free(s);
	}
	else if (ft_strchr(s, '$'))
	{
		ret = parse_env(d, s);
		//free(s);
	}
	return (ret);
}
