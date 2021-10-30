/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 08:47:17 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/30 14:03:05 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	cond_ch_put(t_data *d, char **args, int i)
{
	if (args[i + 1])
	{
		ft_putstr_fd(args[i], d->fd_io[1]);
		ft_putstr_fd(" ", d->fd_io[1]);
	}
	else
		ft_putstr_fd(args[i], d->fd_io[1]);
}
