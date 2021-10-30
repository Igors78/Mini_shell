/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:47:12 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/30 14:03:59 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	is_builtin(char *cmd)
{
	if (!ft_strcmp(cmd, "echo") && ft_strlen(cmd) == 4)
		return (1);
	else if (!ft_strcmp(cmd, "cd") && ft_strlen(cmd) == 2)
		return (1);
	else if (!ft_strcmp(cmd, "pwd") && ft_strlen(cmd) == 3)
		return (1);
	else if (!ft_strcmp(cmd, "export") && ft_strlen(cmd) == 6)
		return (1);
	else if (!ft_strcmp(cmd, "unset") && ft_strlen(cmd) == 5)
		return (1);
	else if (!ft_strcmp(cmd, "env") && ft_strlen(cmd) == 3)
		return (1);
	else if (!ft_strcmp(cmd, "exit") && ft_strlen(cmd) == 4)
		return (1);
	else
		return (0);
}
