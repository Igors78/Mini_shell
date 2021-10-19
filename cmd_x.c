/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:44:38 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/19 13:31:19 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Move the executable file to the first position in the string array if it is not in the first position */
void	cmd_move_x(char **cmd, t_data *d)
{
	char	*tmp;

	if (d->pos_x != 0)
	{
		tmp = cmd[d->pos_i + 1];
		cmd[d->pos_i + 1] = cmd[0];
		cmd[0] = tmp;
	}
}

static void	cmd_exec(t_data *d, int i)
{
	char	**cmd_split;

	cmd_split = ft_splitarg(d->cmd_pipe[i], ' ');
	if (i == 0)
		cmd_move_x(cmd_split, d);
	expand_env(d, cmd_split);
	/* debug */
	//int k = 0;
	//while (cmd_split[k])
	//{
	//	printf("[debug] cmd_split[%d][%d]: %s\n", i, k, cmd_split[k]);
	//	k++;
	//}
	/* /debug */
	if (ft_strchr(cmd_split[0], '/'))
	{
		if (execve(cmd_split[0], cmd_split, d->envv) == -1)
		{
			perror(cmd_split[0]);
			ft_split_free(cmd_split);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		check_path(d, cmd_split[0]);
		if (!d->path)
			return ;
		if (execve(d->path, cmd_split, d->envv) == -1)
			perror("execve() failed");
	}
}

static void	cmd_link_next(t_data *d, int i, int j)
{
	if (d->cmd_pipe[i + 1])
	{
		if (dup2(d->fd_pipe[j + 1], STDOUT_FILENO) < 0)
		{
			perror("dup2() failed");
			exit(EXIT_FAILURE);
		}
	}
	if (j != 0)
	{
		if (dup2(d->fd_pipe[j - 2], 0) < 0)
		{
		    perror("dup2() failed");
		    exit(EXIT_FAILURE);
		}
	}
	i = 0;
	while (i < 2 * d->n_pipe)
	{
		close(d->fd_pipe[i]);
		i++;
	}
}

void	cmd_x(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (d->cmd_pipe[i] && d->fvalid && d->xvalid)
	{
		d->pid = fork();
		if (d->pid == 0)
		{
			cmd_out(d);
			cmd_link_next(d, i, j);
			cmd_exec(d, i);
		}
		else if (d->pid < 0)
			fork_failed(d);
		i++;
		j += 2;
	}
	pipe_end(d);
}
