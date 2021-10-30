/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:09:42 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/30 09:27:34 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Create a temporary file for handling here documents and write to it with gnl.
void	handle_i2_writer(char *eof, t_data *d)
{
	int		i;
	char	*line[2048];

	i = 0;
	d->fd_io[0] = open("_tmp", O_RDWR | O_CREAT, 0644);
	if (d->fd_io[0] == -1)
		open_failed(d);
	while (get_next_line(STDIN_FILENO, line) != 0
		&& ft_strncmp(*line, eof, ft_strlen(eof)) != 0)
	{
		if (write(d->fd_io[0], *line, ft_strlen(*line)) == -1)
			write_failed(d);
		if (write(d->fd_io[0], "\n", 1) == -1)
			write_failed(d);
		free(*line);
		if (++i == 2048)
		{
			printf("the number of new lines reached 2048 limit, stopping\n");
			return ;
		}
	}
	free(*line);
}

/* Handle multiple, position-independent here documents with joined markers. */
int	handle_joined_i2(t_data *d, char **args, int *i)
{
	char	*tmp;
	int		mov;

	if (args[*i][0] == '<' && args[*i][1] == '<' && args[*i][2])
	{
		if (d->file_i > 0 && d->file_i--)
			ft_split_delete_last(args);
		mov = ft_split_move_to_back(args, *i);
		tmp = ft_strdup(&args[*i + mov][2]);
		free(args[*i + mov]);
		args[*i + mov] = tmp;
		handle_i2_writer(args[*i + mov], d);
		ft_split_delete_last(args);
		args[*i + mov] = ft_strdup("_tmp");
		d->file_i++;
		*i = 0;
		return (1);
	}
	return (0);
}

/* Handle multiple, position-independent here documents. */
int	handle_i2(t_data *d, char **args, int *i)
{
	int		mov;

	if (!ft_strcmp(args[*i], "<<") && args[*i + 1])
	{
		if (d->file_i > 0 && d->file_i--)
			ft_split_delete_last(args);
		mov = ft_split_move_to_back(args, *i + 1);
		ft_split_move_to_back(args, *i);
		ft_split_delete_last(args);
		handle_i2_writer(args[*i + mov], d);
		ft_split_delete_last(args);
		args[*i + mov] = ft_strdup("_tmp");
		d->file_i++;
		*i = 0;
		return (1);
	}
	return (0);
}

/* Handle multiple, position-independent input redirection. */
int	handle_i(t_data *d, char **args, int *i)
{
	if (!ft_strcmp(args[*i], "<") && args[*i + 1])
	{
		if (d->file_i > 0 && d->file_i--)
			ft_split_delete_last(args);
		ft_split_move_to_back(args, *i + 1);
		ft_split_move_to_back(args, *i);
		ft_split_delete_last(args);
		d->file_i++;
		*i = 0;
		return (1);
	}
	return (0);
}

/* Handle input redirection markers for each piped command. */
void	handle_input(t_data *d, char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (handle_i(d, args, &i))
			continue ;
		else if (handle_joined_i(d, args, &i))
			continue ;
		else if (handle_i2(d, args, &i))
			continue ;
		else if (handle_joined_i2(d, args, &i))
			continue ;
		i++;
	}
	if (d->file_i > 0)
		check_access(d, args);
}
