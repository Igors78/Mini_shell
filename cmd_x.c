/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:44:38 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/22 22:30:58 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Move the executable file to the first position in the string array if it is not in the first position */
void	cmd_move_x(t_data *d, char **cmd)
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
	char	**args;

	args = ft_splitarg(d->cmd_pipe[i], ' ');
	if (i == 0)
		cmd_move_x(d, args);
	expand_env(d, args);
	/* debug */
	//int k = 0;
	//while (args[k])
	//{
	//	printf("[debug] args[%d][%d]: %s\n", i, k, args[k]);
	//	k++;
	//}
	/* /debug */
	if (ft_strchr(args[0], '/'))
	{
		if (execve(args[0], args, d->envv) == -1)
		{
			perror(args[0]);
			ft_split_free(args);
			exit(EXIT_FAILURE);
		}
	}
	else if (is_builtin(args[0]))
	{
		if (ft_strcmp(args[0], "export") == 0
			&& ft_strlen(args[0]) == 6)
			ft_export(d, args);
	}
	else
	{
		check_path(d, args[0]);
		if (!d->path)
			return ;
		if (execve(d->path, args, d->envv) == -1)
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

void	check_fork(t_data *d, int i)
{
	char	**args;

	args = ft_splitarg(d->cmd_pipe[i], ' ');
	if (i == 0)
		cmd_move_x(d, args);
	expand_env(d, args);
	if (!is_builtin(args[0]))
		d->pid = fork();
	else
		d->flag_builtin = 1;
	free(args);
}

void	cmd_x(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (d->cmd_pipe[i] && d->fvalid && d->xvalid)
	{
		check_fork(d, i);
		if (!d->pid || d->flag_builtin)
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
}
