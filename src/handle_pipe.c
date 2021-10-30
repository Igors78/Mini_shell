/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 12:50:08 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/30 14:03:53 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	handle_pipe(t_data *d, int i, int j)
{
	if (d->cmd_pipe[i + 1])
	{
		if (dup2(d->fd_pipe[j + 1], STDOUT_FILENO) < 0)
			return (dup_failed(d));
	}
	if (j != 0)
	{
		if (dup2(d->fd_pipe[j - 2], 0) < 0)
			return (dup_failed(d));
	}
	i = 0;
	while (i < 2 * d->n_pipe)
		close(d->fd_pipe[i++]);
}
