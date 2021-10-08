/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:28:46 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/08 14:40:54 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_env(t_data *d)
{
	int	i;

	i = 0;
	while (d->cmd[i])
	{
		if (d->cmd[i][0] == '$')
			ft_substitute(d->cmd[i], getenv(&d->cmd[i][1]));
		i++;
	}
}

static void	check_path(t_data *d)
{
	char		**split_path;
	int			i;
	struct stat	st;
	char		*check;
	char		*addslash;

	i = 0;
	split_path = ft_split(getenv("PATH"), ':');
	while (split_path[i])
	{
		addslash = ft_strjoin(split_path[i++], "/");
		check = ft_strjoin(addslash, d->cmd[0]);
		free(addslash);
		if (!stat(check, &st))
		{
			d->path = check;
			ft_split_free(split_path);
			return ;
		}
		else
			free(check);
	}
	printf("%s: command not found\n", d->cmd[0]);
	ft_split_free(split_path);
}

void	ft_interpret(t_data *d)
{
	d->pid = fork();
	if (d->pid == -1)
		perror("fork() failed");
	if (d->pid == 0)
	{
		if (ft_strchr(d->cmd[0], '/'))
		{
			if (execve(d->cmd[0], d->cmd, d->envv) == -1)
				perror("execve() failed");
		}
		else
		{
			check_path(d);
			if (!d->path)
				return ;
			if (execve(d->path, d->cmd, d->envv) == -1)
				perror("execve() failed");
		}
	}
}
