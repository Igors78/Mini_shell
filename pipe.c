/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:46:05 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/18 15:13:50 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_end(t_data *d)
{
	int	status;
	int	i;

	i = 0;
	status = 0;
    while (i < 2 * d->n_pipe)
	{
        close(d->fd_pipe[i]);
		i++;
    }
	i = 0;
    while (i < d->n_pipe + 1)
	{
		wait(&status);
		i++;
	}
	d->exit_status = WEXITSTATUS(status);
	if (d->fd_io[1] != STDOUT_FILENO)
		close(d->fd_io[1]);
}

void	pipe_init(t_data *d)
{
	int	i;

	i = 0;
	if (d->n_pipe > 0)
	{
		d->fd_pipe = ft_calloc(2 * d->n_pipe, sizeof(int));
		while(i < d->n_pipe)
		{
			if (pipe(d->fd_pipe + i * 2) < 0)
			{
				perror("pipe() failed");
				free(d->fd_pipe);
				exit(EXIT_FAILURE);
			}
			i++;
		}
	}
}
