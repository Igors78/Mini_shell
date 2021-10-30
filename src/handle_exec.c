/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:49:14 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/30 15:41:34 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	check_null_path(t_data *d, char *cmd)
{
	char	*tmp;

	tmp = ft_getenv(d, "PATH");
	if (!tmp)
	{
		printf("%s: command not found\n", cmd);
		return (1);
	}
	return (0);
}

static void	exit_gracefully(char **args)
{
	ft_split_free(args);
	exit(EXIT_FAILURE);
}

void	handle_exec(t_data *d, int i)
{
	char	**args;

	args = ft_splitarg(d->cmd_pipe[i], ' ');
	expand_env(d, args);
	handle_input(d, args);
	handle_output(d, args);
	if (ft_strchr(args[0], '/'))
	{
		if (execve(args[0], args, d->envv) == -1)
			exit_gracefully(args);
	}
	else if (is_builtin(args[0]))
		handle_builtins(d, args);
	else
	{
		if (check_null_path(d, args[0]))
			exit_gracefully(args);
		check_path(d, args[0]);
		if (!d->path || execve(d->path, args, d->envv) == -1)
			exit_gracefully(args);
	}
	ft_split_free(args);
}
