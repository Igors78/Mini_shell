/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_comments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:05:39 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/30 14:03:29 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	is_sq(t_data *d, int *i)
{
	if (d->line[*i] == '\'')
	{
		if (d->flag_sq == 0)
			d->flag_sq = 1;
		else
			d->flag_sq = 0;
		*i = *i + 1;
		return (1);
	}
	return (0);
}

static int	is_dq(t_data *d, int *i)
{
	if (d->line[*i] == '\"')
	{
		if (d->flag_dq == 0)
			d->flag_dq = 1;
		else
			d->flag_dq = 0;
		*i = *i + 1;
		return (1);
	}
	return (0);
}

static int	remove_comments(t_data *d, int *i)
{
	char	*tmp;

	d->line[*i] = '\0';
	tmp = ft_strdup(d->line);
	free(d->line);
	d->line = tmp;
	return (1);
}

static void	handle_comments_core(t_data *d)
{
	int		i;

	i = 0;
	while (d->line[i])
	{
		if (is_sq(d, &i))
			continue ;
		if (is_dq(d, &i))
			continue ;
		if (d->line[i] == ' ')
		{
			if (d->line[i + 1])
			{
				if (d->line[i + 1] == '#' && d->flag_sq == 0
					&& d->flag_dq == 0 && remove_comments(d, &i))
					return ;
			}
			else
				return ;
		}
		i++;
	}
}

void	handle_comments(t_data *d)
{
	if (!ft_strncmp(d->line, "#", 1))
	{
		free(d->line);
		d->line = "";
		return ;
	}
	handle_comments_core(d);
}
