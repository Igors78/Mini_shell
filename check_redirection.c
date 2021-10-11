/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:09:42 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/11 13:20:40 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Check if input marker is joined with filename. example: <input sort */
void	check_joined_input(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->n)
	{
		if (d->pos_p1 == -1 || i < d->pos_p1)
		{
			if (d->cmd[i][0] == '<' && d->cmd[i][1] != '<' && ++(d->file_i))
			{
				d->isjoined_i++;
				d->pos_i = i;
			}
			else if (ft_strncmp(d->cmd[i], "<<", 2) == 0
				&& d->cmd[i][3] && ++(d->file_i2))
			{
				d->isjoined_i++;
				d->pos_i = i;
			}
		}
		i++;
	}
}

/* Check if output marker is joined with filename. example: sort >output */
void	check_joined_output(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->n)
	{
		if (d->pos_p2 == -1 || i > d->pos_p2)
		{
			if (d->cmd[i][0] == '>' && d->cmd[i][1] != '>' && ++(d->file_o))
			{
				d->isjoined_o++;
				d->pos_o = i;
			}
			else if (ft_strncmp(d->cmd[i], ">>", 2) == 0 && d->cmd[i][3] && ++(d->file_o2))
			{
				d->isjoined_o++;
				d->pos_o = i;
			}
		}
		i++;
	}
}

void	check_joined(t_data *d)
{
	if (d->pos_i == -1)
		check_joined_input(d);
	if (d->pos_o == -1)
		check_joined_output(d);
}

/* Check for input/output redirection markers and update the data structure */
void	check_redirection(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->n)
	{
		if ((d->pos_p1 == -1 || i < d->pos_p1)
			&& ft_strncmp(d->cmd[i], "<", 3) == 0 && ++(d->file_i))
			d->pos_i = i;
		else if ((d->pos_p1 == -1 || i < d->pos_p1)
			&& ft_strncmp(d->cmd[i], "<<", 4) == 0 && ++(d->file_i2))
			d->pos_i = i;
		else if ((d->pos_p2 == -1 || i > d->pos_p2)
			&& ft_strncmp(d->cmd[i], ">", 3) == 0 && ++(d->file_o))
			d->pos_o = i;
		else if ((d->pos_p2 == -1 || i > d->pos_p2)
			&& ft_strncmp(d->cmd[i], ">>", 4) == 0 && ++(d->file_o2))
			d->pos_o = i;
		i++;
	}
	check_joined(d);
}
