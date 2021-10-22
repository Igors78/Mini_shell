/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:27:45 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/22 23:20:23 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Create a link between opened output file and cmd's output */
void	cmd_out_redirect(t_data *d)
{
	if (d->fd_io[1] == -1)
		open_failed(d);
	if (d->file_o == 1 || d->file_o2 == 1)
	{
		if (!d->flag_builtin && dup2(d->fd_io[1], STDOUT_FILENO) == -1)
			dup_failed(d);
		else
		{
			d->saved_stdout = dup(STDOUT_FILENO);
			if (d->saved_stdout < 0 || dup2(d->fd_io[1], STDOUT_FILENO) == -1)
				dup_failed(d);
		}
	}
}

/* Assign the correct name to output for open() */
char	*cmd_out_name(t_data *d, char *file_o)
{
	if (d->file_o == 1)
	{
		if (d->isjoined_o == 0)
			file_o = d->cmd[d->pos_o + 1];
		else
			file_o = &d->cmd[d->pos_o][1];
	}
	else if (d->file_o2 == 1)
	{
		if (d->isjoined_o == 0)
			file_o = d->cmd[d->pos_o + 1];
		else
			file_o = &d->cmd[d->pos_o][2];
	}
	file_o = check_env(d, file_o);
	return (file_o);
}

/* Given output type, open a file and redirect stdout to that file in desired format */
void	cmd_out(t_data *d)
{
	char	*file_o;

	file_o = NULL;
	file_o = cmd_out_name(d, file_o);
	if (d->file_o == 1)
	{
		if (d->isjoined_o == 0)
			d->fd_io[1] = open(file_o, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else
			d->fd_io[1] = open(file_o, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	else if (d->file_o2 == 1)
	{
		if (d->isjoined_o == 0)
			d->fd_io[1] = open(file_o, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			d->fd_io[1] = open(file_o, O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	cmd_out_redirect(d);
}
