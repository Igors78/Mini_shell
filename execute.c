/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:15:40 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/09 16:11:02 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_data *d)
{
	free(d->line);
	rl_clear_history();
	ft_split_free(d->cmd);
	exit (0);
}

void	ft_cd(t_data *d)
{
	if (NULL == d->cmd[1])
		printf("Argument needed for \"cd\"\n");
	else
	{
		if (chdir(d->cmd[1]) != 0)
			printf("Unknown path for \"cd\"\n");
	}
}

void	ft_env(t_data *d)
{
	int	i;

	i = 0;
	while (d->envv[i])
		printf("%s\n", d->envv[i++]);
}

void	execute(t_data *d)
{
	if (ft_strncmp(d->cmd[0], "exit", 5) == 0 && ft_strlen(d->cmd[0]) == 4)
		ft_exit(d);
	else if (ft_strncmp(d->cmd[0], "cd", 3) == 0 && ft_strlen(d->cmd[0]) == 2)
		ft_cd(d);
	else if (ft_strncmp(d->cmd[0], "export", 6) == 0
		&& ft_strlen(d->cmd[0]) == 6)
		ft_export(d);
	// else if (ft_strncmp(d->cmd[0], "unset", 6) == 0
	// 	&& ft_strlen(d->cmd[0]) == 5)
	// 	ft_unset(d);
	else
		ft_interpret(d);
}
