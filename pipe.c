/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:46:05 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/30 09:37:36 by ioleinik         ###   ########.fr       */
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
	if (!d->flag_builtin)
		d->exit_status = WEXITSTATUS(status);
	if (d->fd_io[1] != STDOUT_FILENO)
		close(d->fd_io[1]);
	if (d->n_pipe > 0)
		free(d->fd_pipe);
}

/* Count and return the number of pipes in d->cmd */
static int	pipe_count(char **cmd)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (cmd[i])
	{
		if (ft_strncmp(cmd[i], "|", 2) == 0)
			n++;
		i++;
	}
	return (n);
}

void	pipe_init(t_data *d)
{
	int	i;

	d->n_pipe = pipe_count(d->cmd);
	i = 0;
	if (d->n_pipe > 0)
	{
		d->fd_pipe = ft_calloc(2 * d->n_pipe, sizeof(int));
		while (i < d->n_pipe)
		{
			if (pipe(d->fd_pipe + i * 2) < 0)
				pipe_failed(d);
			i++;
		}
	}
}
