/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:50:54 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/22 10:30:46 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	chk_sing_quo(t_data *d, char **spl, int *i)
{
	char	*tmp;

	if (spl[*i][0] == '\'' && spl[*i][1] == '$'
			&& spl[*i][ft_strlen(spl[*i]) - 1] == '\'')
	{
		if (spl[*i][2] == '{'
				&& spl[*i][ft_strlen(spl[*i]) - 2] == '}')
		{
			spl[*i][ft_strlen(spl[*i]) - 2] = '\0';
			tmp = ft_getenv(d, &spl[*i][3]);
		}
		else if (spl[*i][2] == '?' && spl[*i][3] == '\'')
			tmp = ft_itoa(d->exit_status);
		else
		{
			spl[*i][ft_strlen(spl[*i]) - 1] = '\0';
			tmp = ft_getenv(d, &spl[*i][2]);
		}
		if (!tmp)
			return ;
		free(spl[*i]);
		spl[*i] = ft_strdup(tmp);
	}
}

void	chk_curl_br(t_data *d, char **spl, int *i)
{
	char	*tmp;

	if (spl[*i][0] == '$')
	{
		if (spl[*i][1] == '{'
				&& spl[*i][ft_strlen(spl[*i]) - 1] == '}')
		{
			spl[*i][ft_strlen(spl[*i]) - 1] = '\0';
			tmp = ft_getenv(d, &spl[*i][2]);
		}
		else if (spl[*i][1] == '?')
			tmp = ft_itoa(d->exit_status);
		else
			tmp = ft_getenv(d, &spl[*i][1]);
		if (!tmp)
			return ;
		free(spl[*i]);
		spl[*i] = ft_strdup(tmp);
	}
}

void	free_memory(t_data *d)
{
	if (d->envv)
		ft_split_free(d->envv);
	if (d->cmd)
		ft_split_free(d->cmd);
	if (d->line)
		free(d->line);
	if (d->path)
		free(d->path);
}

void	put_strarr(char **arr)
{
	int	i = 0;

	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
}

char	*trim_quot(char *s)
{
	char	*tmp;

	if (s[0] == '\'' && s[ft_strlen(s) - 1] == '\'')
	{
		s[ft_strlen(s) - 1] = '\0';
		tmp = ft_strdup(&s[1]);
		free(s);
		s = tmp;
		free(tmp);
		return (s);
	}
	if (s[0] == '\"' && s[ft_strlen(s) - 1] == '\"')
	{
		s[ft_strlen(s) - 1] = '\0';
		tmp = ft_strdup(&s[1]);
		free(s);
		s = tmp;
		free(tmp);
		return (s);
	}
	return (s);
}
