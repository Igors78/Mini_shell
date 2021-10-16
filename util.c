/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:50:54 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/16 20:36:48 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_memory(t_data *d)
{
	if (d->envv)
		ft_split_free(d->envv);
	if (d->cmd)
		ft_split_free(d->cmd);
	if (d->line)
		free(d->line);
	if (d->path)
		free(d->path);
}
