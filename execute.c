/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:15:40 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/22 15:44:47 by ioleinik         ###   ########.fr       */
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
	char	*x;

	x = d->cmd[0];
	x = check_env(d, x);
	if (ft_strcmp(x, "exit") == 0 && ft_strlen(x) == 4)
		ft_exit(d);
	else if (ft_strcmp(x, "cd") == 0 && ft_strlen(x) == 2)
		ft_cd(d);
	else if (ft_strcmp(x, "export") == 0
		&& ft_strlen(x) == 6)
		ft_export(d);
	else if (ft_strcmp(x, "unset") == 0
		&& ft_strlen(x) == 5)
	{
		if (!d->cmd[1])
		{
			d->exit_status = 1;
			return ;
		}
		if (find_unset(d) > 0)
		{
			d->envv = ft_unset(d->envv, find_unset(d));
			d->exit_status = 0;
		}
		else
		{
			d->exit_status = 1;
			return ;
		}
	}
	else
		cmd_x(d);
}
