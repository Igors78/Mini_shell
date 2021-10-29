/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:04:02 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/29 18:02:44 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
