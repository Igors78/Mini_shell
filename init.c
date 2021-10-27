/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:44:51 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/26 23:04:43 by mbarut           ###   ########.fr       */
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
	d->file_i = 0;
	d->file_o = 0;
	d->file_i2 = 0;
	d->file_o2 = 0;
	d->fd_io[0] = STDIN_FILENO;
	d->fd_io[1] = STDOUT_FILENO;
	d->flag_builtin = 0;
	d->saved_stdout = 0;
	d->flag_sq = 0;
	d->flag_dq = 0;
}
