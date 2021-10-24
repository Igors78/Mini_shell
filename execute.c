/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:15:40 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/24 13:41:36 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* All commands go through here */
void	execute(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (d->cmd_pipe[i])
	{
		handle_fork(d, i);
		if (!d->pid || d->flag_builtin)
		{
			handle_pipe(d, i, j);
			handle_exec(d, i);
		}
		else if (d->pid < 0)
			fork_failed(d);
		i++;
		j += 2;
	}
}
