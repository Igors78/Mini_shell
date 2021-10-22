/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:28:46 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/22 23:21:18 by mbarut           ###   ########.fr       */
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
	perror("open() failed for output file");
	if (!d->flag_builtin)
		exit(EXIT_FAILURE);
	else
		return ;
}

void	x_access_failed(t_data *d)
{
	d->xvalid = 0;
	d->pos_x = -1;
	perror("error finding the provided command");
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
