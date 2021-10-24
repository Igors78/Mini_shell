/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:50:40 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/24 12:53:03 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	skip_to_executable(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!ft_strcmp(args[i], "<") && args[i + 1])
		{
			i += 2;
			continue ;
		}
		else if (!ft_strcmp(args[i], "<<") && args[i + 1])
		{
			i += 2;
			continue ;
		}
		else if (args[i][0] == '<' && args[i][1] != '<' && i++)
			continue ;
		else if (args[i][0] == '<' && args[i][1] == '<' && args[i][2] && i++)
			continue ;
		else
			break ;
	}
	return (i);
}

void	handle_fork(t_data *d, int i)
{
	char	**args;
	int		pos_exe;

	args = ft_splitarg(d->cmd_pipe[i], ' ');
	expand_env(d, args);
	pos_exe = skip_to_executable(args);
	if (!is_builtin(args[pos_exe]))
		d->pid = fork();
	else
		d->flag_builtin = 1;
	free(args);
}
