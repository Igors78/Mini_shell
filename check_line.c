/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:32:55 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/17 16:07:42 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Debugging function for checking correct parsing of read lines onto t_data */
void	check_parsing(t_data *d)
{
	printf("\tsplit elements: %i\n", d->n);
	printf("\tpipes: %i\n", d->n_pipe);
	printf("\tposition of first pipe: %i\n", d->pos_p1);
	printf("\tposition of last pipe: %i\n", d->pos_p2);
	printf("\tinput redirection: %i\n", d->file_i);
	printf("\toutput redirection: %i\n", d->file_o);
	printf("\tinput redirection with here: %i\n", d->file_i2);
	printf("\toutput redirection that appends: %i\n", d->file_o2);
}

/* Find the position of the desired pipe in d->cmd */
/* n must be the number of substrings */
static int	find_pos_pipe(int desired_pipe, char **cmd, int n)
{
	int	i;

	i = 0;
	if (desired_pipe == pipe_first)
	{
		while (cmd[i])
		{
			if (ft_strncmp(cmd[i], "|", 2) == 0)
				return (i);
			i++;
		}
	}
	else if (desired_pipe == pipe_last)
	{
		while (n-- > 0)
		{
			if (ft_strncmp(cmd[n], "|", 2) == 0)
				return (n);
		}
	}
	return (-1);
}

/* Count and return the number of pipes in d->cmd */
static int	pipe_count(char **cmd)
{
	int	i;
	int	n;

	n = 0;
	i = 0;
	while (cmd[i])
	{
		if (ft_strncmp(cmd[i], "|", 2) == 0)
			n++;
		i++;
	}
	return (n);
}

/* Count and return the number of individual strings in d->cmd */
static int	n_count(char **cmd)
{
	int	i;

	i = 0;
	if (!cmd || !cmd[0])
		return (0);
	while (cmd[i])
		i++;
	return (i);
}

/* Check the read line for redirection and pipe markers and start execution */
void	check_line(t_data *d)
{
	d->n = n_count(d->cmd);
	d->n_pipe = pipe_count(d->cmd);
	d->pos_p1 = find_pos_pipe(pipe_first, d->cmd, d->n);
	d->pos_p2 = find_pos_pipe(pipe_last, d->cmd, d->n);
	check_redirection(d);
	check_io(d);
	check_x(d);
	//check_parsing(d);
}
