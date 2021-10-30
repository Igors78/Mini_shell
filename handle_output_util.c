/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_output_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 09:29:41 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/30 13:22:59 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Create a link between opened output file and cmd's output. */
void	cmd_out_redirect(t_data *d)
{
	if (d->fd_io[1] == -1)
		return (open_failed(d));
	if (!d->flag_builtin && dup2(d->fd_io[1], STDOUT_FILENO) == -1)
		return (dup_failed(d));
	else
	{
		d->saved_stdout = dup(STDOUT_FILENO);
		if (d->saved_stdout < 0 || dup2(d->fd_io[1], STDOUT_FILENO) == -1)
			return (dup_failed(d));
	}
}
