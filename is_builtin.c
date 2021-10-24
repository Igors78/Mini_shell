/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:47:12 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/24 16:51:18 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *cmd)
{
	// if (ft_strcmp(cmd, "echo") == 0 && ft_strlen(cmd) == 4)
	// 	return (1);
	if (ft_strcmp(cmd, "cd") == 0 && ft_strlen(cmd) == 2)
		return (1);
	// else if (ft_strcmp(cmd, "pwd") == 0 && ft_strlen(cmd) == 3)
	// 	return (1);
	else if (ft_strcmp(cmd, "export") == 0 && ft_strlen(cmd) == 6)
		return (1);
	else if (ft_strcmp(cmd, "unset") == 0 && ft_strlen(cmd) == 5)
		return (1);
	// else if (ft_strcmp(cmd, "env") == 0 && ft_strlen(cmd) == 3)
	// 	return (1);
	else if (ft_strcmp(cmd, "exit") == 0 && ft_strlen(cmd) == 4)
		return (1);
	else
		return (0);
}
