/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:44:51 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/19 09:09:24 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_data *d)
{
	init_sig();
	d->path = NULL;
	d->pid = -42;
	d->cmd = NULL;
	d->cmd_pipe = NULL;
	d->xvalid = 1;
	d->fvalid = 1;
	d->file_i = 0;
	d->file_o = 0;
	d->file_i2 = 0;
	d->fname_i2 = NULL;
	d->file_o2 = 0;
	d->pos_i = -1;
	d->pos_o = -1;
	d->pos_x = 0;
	d->isjoined_i = 0;
	d->isjoined_o = 0;
	d->exit_status = 0; // (!) assuming minishell does not inherit the exit code from the environment
	d->fd_io[0] = STDIN_FILENO;
	d->fd_io[1] = STDOUT_FILENO;
}
