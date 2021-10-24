/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:49:14 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/24 12:50:27 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_exec(t_data *d, int i)
{
	char	**args;

	args = ft_splitarg(d->cmd_pipe[i], ' ');
	expand_env(d, args);
	handle_input(d, args);
	handle_output(d, args);
	/* debug */
	//int k = 0;
	//while (args[k])
	//{
	//	printf("[debug] args[%d][%d]: %s\n", i, k, args[k]);
	//	k++;
	//}
	/* /debug */
	if (ft_strchr(args[0], '/'))
	{
		if (execve(args[0], args, d->envv) == -1)
		{
			perror(args[0]);
			ft_split_free(args);
			exit(EXIT_FAILURE);
		}
	}
	else if (is_builtin(args[0]))
		handle_builtins(d, args);
	else
	{
		check_path(d, args[0]);
		if (!d->path)
			return ;
		if (execve(d->path, args, d->envv) == -1)
			perror("execve() failed");
	}
}
