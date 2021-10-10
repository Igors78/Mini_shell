/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 07:26:37 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/10 10:55:19 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exportarg(t_data *d)
{
	if (!ft_strchr(d->cmd[1], '='))
		return ;
	d->envv = ft_addstrstrarr(d->envv, d->cmd[1]);
}
