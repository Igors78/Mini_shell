/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:49:14 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/30 09:21:04 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_gracefully(char **args)
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
		check_path(d, args[0]);
		if (!d->path || execve(d->path, args, d->envv) == -1)
			exit_gracefully(args);
	}
	ft_split_free(args);
}
