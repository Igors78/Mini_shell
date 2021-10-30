/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_to_executable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:23:52 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/30 15:24:14 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	skip_to_executable(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!ft_strcmp(args[i], "<") && args[i + 1])
		{
			i += 2;
			continue ;
		}
		else if (!ft_strcmp(args[i], "<<") && args[i + 1])
		{
			i += 2;
			continue ;
		}
		else if (args[i][0] == '<' && args[i][1] != '<' && i++)
			continue ;
		else if (args[i][0] == '<' && args[i][1] == '<' && args[i][2] && i++)
			continue ;
		else
			break ;
	}
	return (i);
}
