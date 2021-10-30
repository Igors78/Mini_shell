/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:04:02 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/30 14:02:59 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	expand_env(t_data *d, char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		cmd[i] = check_env(d, cmd[i]);
		cmd[i] = trim_quot(cmd[i]);
		i++;
	}
}
