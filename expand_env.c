/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:04:02 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/17 16:07:54 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	stick_back(char **spl, char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	free (s);
	s = ft_strnew(0);
	while (spl[i])
	{
		tmp = s;
		s = ft_strjoin(tmp, spl[i]);
		free (tmp);
		i++;
	}
}

static void	expand_dbl_quot(t_data *d, char *s)
{
	int		i;
	char	*tmp;
	char	**spl;

	i = 0;
	tmp = NULL;
	spl = ft_split(s, ' ');
	while (spl[i])
	{
		if (chk_sing_quo(d, spl, &i, tmp))
			continue ;
		if (chk_curl_br(d, spl, &i, tmp))
			continue ;
		i++;
	}
	stick_back(spl, s);
}

static void	condition_statement(t_data *d, int *i)
{
	char	*tmp;

	if (d->cmd[*i][0] == '\'' && d->cmd[*i][ft_strlen(d->cmd[*i]) - 1] == '\'')
		return ;
	else if (d->cmd[*i][0] == '\"'
		&& d->cmd[*i][ft_strlen(d->cmd[*i]) - 1] == '\"')
		expand_dbl_quot(d, d->cmd[*i]);
	else if (d->cmd[*i][0] == '$')
	{
		if (d->cmd[*i][1] == '{'
				&& d->cmd[*i][ft_strlen(d->cmd[*i]) - 1] == '}')
		{
			d->cmd[*i][ft_strlen(d->cmd[*i]) - 1] = '\0';
			tmp = ft_getenv(d, &d->cmd[*i][2]);
		}
		else
			tmp = ft_getenv(d, &d->cmd[*i][1]);
		if (!tmp)
			return ;
		free(d->cmd[*i]);
		d->cmd[*i] = ft_strdup(tmp);
	}
}

void	expand_env(t_data *d)
{
	int		i;

	i = 0;
	while (d->cmd[i])
	{
		condition_statement(d, &i);
		printf("%s debug\n", d->cmd[i]);
		i++;
	}
}
