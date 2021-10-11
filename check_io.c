/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:23:49 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/11 13:23:04 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Create a temporary file for handling here documents and write to it with gnl
void	handle_i(char *eof, t_data *d)
{
	int		i;
	char	*line[2048];

	i = 0;
	d->fd_io[0] = open(eof, O_RDWR | O_CREAT, 0644);
	if (d->fd_io[0] == -1)
	{
		perror("open() failed for input file");
		exit(EXIT_FAILURE);
	}
	while (get_next_line(STDIN_FILENO, line) != 0
		&& ft_strncmp(*line, eof, ft_strlen(eof)) != 0)
	{
		write(d->fd_io[0], *line, ft_strlen(*line));
		write(d->fd_io[0], "\n", 1);
		i++;
		if (i == 2048)
		{
			printf("the number of new lines reached 2048 limit");
			unlink(eof);
			exit(EXIT_FAILURE);
		}
	}
	d->fname_i2 = eof;
}

/* Check if the files pointed by input/output redirection markers are valid */
void	check_io(t_data *d)
{
	if (d->file_i > 1 || d->file_o > 1
		|| d->file_i2 > 1 || d->file_o2 > 1
		|| d->isjoined_i > 1 || d->isjoined_o > 1)
		d->fvalid = 0;
	if (d->file_i == 1 && d->file_i2 == 1)
		d->fvalid = 0;
	if (d->file_o == 1 && d->file_o2 == 1)
		d->fvalid = 0;
	if (d->file_i == 1)
	{
		if (d->isjoined_i)
		{
			if (access(&d->cmd[d->pos_i][1], F_OK) != 0 || access(&d->cmd[d->pos_i][1], R_OK) != 0)
			{
				d->fvalid = 0;
				perror("error accessing input file");
			}
		}
		else
		{
			if (access(d->cmd[d->pos_i + 1], F_OK) != 0 || access(d->cmd[d->pos_i + 1], R_OK) != 0)
			{
				printf("%s\n", d->cmd[d->pos_i + 1]);
				d->fvalid = 0;
				perror("error accessing input file");
			}
		}
	}
	if (d->file_i2 == 1)
	{
		if (d->isjoined_i)
			handle_i(&d->cmd[d->pos_i][2], d);
		else
			handle_i(d->cmd[d->pos_i + 1], d);
	}
}
