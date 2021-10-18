/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:04:02 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/18 10:57:51 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	stick_back(char **spl, char *s)
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
	s = ft_strdup(tmp);
	free(tmp);
	printf("%s\n", s);
}

static void	expand_dbl_quot(t_data *d, char *s)
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
	stick_back(spl, s);
}

static void	condition_statement(t_data *d, char **cmd, int *i)
{
	char	*tmp;

	if (cmd[*i][0] == '\'' && cmd[*i][ft_strlen(cmd[*i]) - 1] == '\'')
		return ;
	else if (cmd[*i][0] == '\"'
		&& cmd[*i][ft_strlen(cmd[*i]) - 1] == '\"')
	{
		expand_dbl_quot(d, cmd[*i]);
		printf("debug %s\n", cmd[*i]);
	}
	else if (cmd[*i][0] == '$')
	{
		if (cmd[*i][1] == '{'
				&& cmd[*i][ft_strlen(cmd[*i]) - 1] == '}')
		{
			cmd[*i][ft_strlen(cmd[*i]) - 1] = '\0';
			tmp = ft_getenv(d, &cmd[*i][2]);
		}
		else
			tmp = ft_getenv(d, &cmd[*i][1]);
		if (!tmp)
			return ;
		free(cmd[*i]);
		cmd[*i] = ft_strdup(tmp);
	}
}

void	expand_env(t_data *d, char **cmd)
{
	int		i;

	i = 0;
	while (cmd[i])
	{
		condition_statement(d, cmd, &i);
		// printf("debug %s\n", cmd[i]);
		i++;
	}
}
