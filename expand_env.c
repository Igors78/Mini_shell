/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:04:02 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/17 17:18:56 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//static void	stick_back(char **spl, char *s)
//{
//	int		i;
//	char	*tmp;
//
//	i = 0;
//	free (s);
//	s = ft_strnew(0);
//	while (spl[i])
//	{
//		tmp = s;
//		s = ft_strjoin(tmp, spl[i]);
//		free (tmp);
//		i++;
//	}
//}

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
	//stick_back(spl, s); <- including this breaks elements inside quotes 
}

static void	condition_statement(t_data *d, char **cmd, int *i)
{
	char	*tmp;

	if (cmd[*i][0] == '\'' && cmd[*i][ft_strlen(cmd[*i]) - 1] == '\'')
		return ;
	else if (cmd[*i][0] == '\"'
		&& cmd[*i][ft_strlen(cmd[*i]) - 1] == '\"')
			expand_dbl_quot(d, cmd[*i]);
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
		i++;
	}
}
