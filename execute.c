/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:15:40 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/16 20:41:24 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_data *d)
{
	(void)d;
	//free_memory(d); <- causes double free error with ctrl+d
	exit (0);
}

static void	ft_cd(t_data *d)
{
	if (NULL == d->cmd[1])
		printf("Argument needed for \"cd\"\n");
	else
	{
		if (chdir(d->cmd[1]) != 0)
			printf("Unknown path for \"cd\"\n");
	}
}

static int	find_unset(t_data *d)
{
	int		i;
	char	*env_tmp;

	i = 0;
	while (d->envv[i])
	{
		env_tmp = ft_strdup(d->envv[i]);
		*(ft_strchr(env_tmp, '=')) = '\0';
		if (ft_strcmp(env_tmp, d->cmd[1]) == 0)
		{
			free(env_tmp);
			return (i);
		}
		free(env_tmp);
		i++;
	}
	return (-1);
}

static char	**ft_unset(char **arr, int index)
{
	char	**new;
	int		i;
	int		k;

	i = 0;
	k = 0;
	new = (char **)malloc(sizeof(char *) * (ft_strarrlen(arr) + 1));
	while (i < ft_strarrlen(arr))
	{
		if (i == index)
			i++;
		new[k] = ft_strdup(arr[i]);
		i++;
		k++;
	}
	new[k] = NULL;
	ft_split_free(arr);
	return (new);
}

void	execute(t_data *d)
{
	if (ft_strcmp(d->cmd[0], "exit") == 0 && ft_strlen(d->cmd[0]) == 4)
		ft_exit(d);
	else if (ft_strcmp(d->cmd[0], "cd") == 0 && ft_strlen(d->cmd[0]) == 2)
		ft_cd(d);
	else if (ft_strcmp(d->cmd[0], "export") == 0
		&& ft_strlen(d->cmd[0]) == 6)
		ft_export(d);
	else if (ft_strcmp(d->cmd[0], "unset") == 0
		&& ft_strlen(d->cmd[0]) == 5)
	{
		if (!d->cmd[1])
			return ;
		if (find_unset(d) > 0)
			d->envv = ft_unset(d->envv, find_unset(d));
		else
			return ;
	}
	else
		cmd_x(d);
}
