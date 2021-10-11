/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 15:28:46 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/11 13:47:19 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fork_failed(t_data *d)
{
	perror("fork() failed");
	if (d->fd_io[1] != STDOUT_FILENO)
		close(d->fd_io[1]);
	exit(EXIT_FAILURE);
}

void	open_failed(void)
{
	perror("open() failed for output file");
	exit(EXIT_FAILURE);
}

void	x_access_failed(t_data *d)
{
	d->xvalid = 0;
	d->pos_x = -1;
	perror("error finding the provided command");
	return ;
}
