/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 10:47:12 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/19 18:56:43 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_data *d)
{
	char	*x;

	x = d->cmd[0];
	if (ft_strcmp(x, "exit") == 0 && ft_strlen(x) == 4)
		return (1);
	else if (ft_strcmp(x, "cd") == 0 && ft_strlen(x) == 2)
		return (1);
	else if (ft_strcmp(x, "export") == 0
		&& ft_strlen(x) == 6)
		return (1);
	else if (ft_strcmp(x, "unset") == 0
		&& ft_strlen(x) == 5)
		return (1);
	else
		return (0);
}
