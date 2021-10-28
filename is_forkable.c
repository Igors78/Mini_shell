/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_forkable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 22:52:29 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/28 13:19:57 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_forkable(char **args, int pos_exe)
{
	char	*cmd;

	cmd = args[pos_exe];
	if (!ft_strcmp(cmd, "echo") && ft_strlen(cmd) == 4)
		return (1);
	else if (!ft_strcmp(cmd, "cd") && ft_strlen(cmd) == 2)
		return (0);
	else if (!ft_strcmp(cmd, "pwd") && ft_strlen(cmd) == 3)
		return (1);
	else if (!ft_strcmp(cmd, "export") && ft_strlen(cmd) == 6)
	{
		if (args[pos_exe + 1] && args[pos_exe + 1][0] != '>')
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
