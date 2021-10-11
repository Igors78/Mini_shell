/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:27:45 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/11 14:12:24 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Create a link between opened output file and cmd's output */
void	cmd_out_redirect(t_data *d)
{
	int	ret;

	if (d->file_o == 1 || d->file_o2 == 1)
		ret = dup2(d->fd_io[1], STDOUT_FILENO);
	if (ret == -1)
	{
		perror("dup2() failed");
		exit(EXIT_FAILURE);
	}	
}

/* Given output type, open a file and redirect stdout to that file in desired format */
void	cmd_out(t_data *d)
{
	if (d->file_o == 1)
	{
		if (d->isjoined_o == 0)
			d->fd_io[1] = open(d->cmd[d->pos_o + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else
			d->fd_io[1] = open(&d->cmd[d->pos_o][1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	else if (d->file_o2 == 1)
	{
		if (d->isjoined_o == 0)
			d->fd_io[1] = open(d->cmd[d->pos_o + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			d->fd_io[1] = open(&d->cmd[d->pos_o][2], O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	if (d->fd_io[1] == -1)
		open_failed();
	cmd_out_redirect(d);
}
