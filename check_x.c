/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:29:01 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/19 19:55:08 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* get the positions of pipes in the given string array and store it in array */
/* d->pos_pipe needs to be freed after consumed */
void	get_pipe_pos(t_data *d)
{
	int	i;
	int	j;

	if (d->n_pipe > 0)
	{
		d->pos_pipe = ft_calloc(d->n_pipe, sizeof(int));
		i = 0;
		j = 0;
		while (d->cmd[i])
		{
			if (ft_strncmp(d->cmd[i], "|", 2) == 0)
				d->pos_pipe[j++] = i;
			i++;
		}
	}
}

/* Check if the executable file is accessible */
void	try_access_x(t_data *d)
{
	char	*x;

	if (is_builtin(d))
		return ;
	x = d->cmd[d->pos_x];
	x = check_env(d, x);
	if (ft_strchr(x, '/'))
	{
		if (access(x, X_OK) != 0)
			x_access_failed(d);
	}
	else
	{
		check_path(d, x);
		if (!d->path)
			return ;
		if (access(d->path, X_OK) != 0)
			x_access_failed(d);
	}
}

/* Check if executables are accessible depending on pipe positions */
void	detect_pos_x(t_data *d, int pos_x)
{
	int	n;
	int	i;

	n = d->n_pipe;
	i = 0;
	d->pos_x = pos_x;
	try_access_x(d);
	while (n-- > 0)
	{
		d->pos_x = d->pos_pipe[i++] + 1;
		try_access_x(d);
	}
}

/* Check if executables in d->cmd are accessible */
void	check_x(t_data *d)
{
	get_pipe_pos(d);
	if (d->fvalid == 1)
	{
		if (d->file_i == 1 || d->file_i2 == 1)
		{
			if (d->pos_i == 0)
				detect_pos_x(d, 2 - d->isjoined_i);
			else if (d->pos_i > 0)
				detect_pos_x(d, 0);
		}
		else
			detect_pos_x(d, 0);
	}
}
