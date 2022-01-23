/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_forkable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:52:29 by mbarut            #+#    #+#             */
/*   Updated: 2022/01/23 10:29:25 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_forkable(char *cmd, char *cmd_next)
{
	if (!cmd)
		return (1);
	if (!ft_strcmp(cmd, "echo") && ft_strlen(cmd) == 4)
		return (1);
	else if (!ft_strcmp(cmd, "cd") && ft_strlen(cmd) == 2)
		return (0);
	else if (!ft_strcmp(cmd, "pwd") && ft_strlen(cmd) == 3)
		return (1);
	else if (!ft_strcmp(cmd, "export") && ft_strlen(cmd) == 6)
	{
		if (cmd_next && cmd_next[0] != '>')
			return (0);
		else
			return (1);
	}
	else if (!ft_strcmp(cmd, "unset") && ft_strlen(cmd) == 5)
		return (0);
	else if (!ft_strcmp(cmd, "env") && ft_strlen(cmd) == 3)
		return (1);
	else if (!ft_strcmp(cmd, "exit") && ft_strlen(cmd) == 4)
		return (0);
	else
		return (1);
}
