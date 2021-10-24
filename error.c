/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:28:46 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/24 13:22:03 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fork_failed(t_data *d)
{
	perror("fork() failed");
	if (d->fd_io[1] != STDOUT_FILENO)
		close(d->fd_io[1]);
	if (!d->flag_builtin)
		exit(EXIT_FAILURE);
	else
		return ;
}

void	open_failed(t_data *d)
{
	perror("open() failed");
	if (!d->flag_builtin)
		exit(EXIT_FAILURE);
	else
		return ;
}

void	dup_failed(t_data *d)
{
	perror("dup2() failed");
	if (!d->flag_builtin)
		exit(EXIT_FAILURE);
	else
		return ;
}

void	pipe_failed(t_data *d)
{
	perror("pipe() failed");
	free(d->fd_pipe);
	if (!d->flag_builtin)
		exit(EXIT_FAILURE);
	else
		return ;
}

void	write_failed(t_data *d)
{
	perror("write() failed");
	if (!d->flag_builtin)
		exit(EXIT_FAILURE);
	else
		return ;
}
