/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:50:40 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/30 15:24:19 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	handle_fork(t_data *d, int *i, int *j)
{
	char	**args;
	int		pos_exe;

	args = ft_splitarg(d->cmd_pipe[*i], ' ');
	expand_env(d, args);
	pos_exe = skip_to_executable(args);
	d->flag_forked = is_forkable(args, pos_exe);
	if (d->flag_forked)
		d->pid = fork();
	else
	{
		handle_builtins(d, args);
		*i = *i + 1;
		*j = *j + 2;
		ft_split_free(args);
		return (0);
	}
	ft_split_free(args);
	return (1);
}
