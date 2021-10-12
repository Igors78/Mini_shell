/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:47:12 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/12 10:54:46 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_data *d)
{
	if (ft_strcmp(d->cmd[0], "exit") == 0 && ft_strlen(d->cmd[0]) == 4)
		return (1);
	else if (ft_strcmp(d->cmd[0], "cd") == 0 && ft_strlen(d->cmd[0]) == 2)
		return (1);
	else if (ft_strcmp(d->cmd[0], "export") == 0
		&& ft_strlen(d->cmd[0]) == 6)
		return (1);
	else if (ft_strcmp(d->cmd[0], "unset") == 0
		&& ft_strlen(d->cmd[0]) == 5)
		return (1);
	else
		return (0);
}
