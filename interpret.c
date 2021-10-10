/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:28:46 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/10 15:53:47 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_getenv(t_data *d, char *str)
{
	int		i;
	char	*env_tmp;

	i = 0;
	while (d->envv[i])
	{
		env_tmp = ft_strdup(d->envv[i]);
		*(ft_strchr(env_tmp, '=')) = '\0';
		if (ft_strcmp(env_tmp, str) == 0)
		{
			free(env_tmp);
			return (ft_strchr(d->envv[i], '=') + 1);
		}
		free(env_tmp);
		i++;
	}
	return (NULL);
}

void	expand_env(t_data *d)
{
	int		i;
	char	*tmp;

	i = 0;
	while (d->cmd[i])
	{
		if (d->cmd[i][0] == '$')
		{
			if (d->cmd[i][1] == '{'
				&& d->cmd[i][ft_strlen(d->cmd[i]) - 1] == '}')
			{
				d->cmd[i][ft_strlen(d->cmd[i]) - 1] = '\0';
				tmp = ft_getenv(d, &d->cmd[i][2]);
			}
			else
				tmp = ft_getenv(d, &d->cmd[i][1]);
			if (!tmp)
				return ;
			free(d->cmd[i]);
			d->cmd[i] = ft_strdup(tmp);
		}
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
	split_path = ft_split(ft_getenv(d, "PATH"), ':');
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
