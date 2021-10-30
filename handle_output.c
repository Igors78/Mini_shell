/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:27:45 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/30 09:32:55 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Handle multiple, position-independ, appending out redir with joined markers.
int	handle_joined_o2(t_data *d, char **args, int *i)
{
	char	*tmp;
	int		mov;

	if (args[*i][0] == '>' && args[*i][1] == '>' && args[*i][2])
	{
		if (d->file_o > 0 && d->file_o--)
			close(d->fd_io[1]);
		mov = ft_split_move_to_back(args, *i);
		tmp = ft_strdup(&args[*i + mov][2]);
		free(args[*i + mov]);
		args[*i + mov] = tmp;
		d->fd_io[1] = open(args[*i + mov], O_WRONLY | O_CREAT | O_APPEND, 0644);
		ft_split_delete_last(args);
		d->file_o++;
		*i = 0;
		return (1);
	}
	return (0);
}

/* Handle multiple, position-independent, appending output redirection. */
int	handle_o2(t_data *d, char **args, int *i)
{
	int		mov;

	if (!ft_strcmp(args[*i], ">>") && args[*i + 1])
	{
		if (d->file_o > 0 && d->file_o--)
			close(d->fd_io[1]);
		mov = ft_split_move_to_back(args, *i + 1);
		ft_split_move_to_back(args, *i);
		d->fd_io[1] = open(args[*i + mov], O_WRONLY | O_CREAT | O_APPEND, 0644);
		ft_split_delete_last(args);
		ft_split_delete_last(args);
		d->file_o++;
		*i = 0;
		return (1);
	}
	return (0);
}

/* Handle multiple, position-independent, truncating output redirection. */
int	handle_o(t_data *d, char **args, int *i)
{
	int	mov;

	if (!ft_strcmp(args[*i], ">") && args[*i + 1])
	{
		if (d->file_o > 0 && d->file_o--)
			close(d->fd_io[1]);
		mov = ft_split_move_to_back(args, *i + 1);
		ft_split_move_to_back(args, *i);
		d->fd_io[1] = open(args[*i + mov], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		ft_split_delete_last(args);
		ft_split_delete_last(args);
		d->file_o++;
		*i = 0;
		return (1);
	}
	return (0);
}

//Handle multiple, position-independ, trunc output redir with joined markers
int	handle_joined_o(t_data *d, char **args, int *i)
{
	char	*tmp;
	int		mov;

	if (args[*i][0] == '>' && args[*i][1] && args[*i][1] != '>')
	{
		if (d->file_o > 0 && d->file_o--)
			close(d->fd_io[1]);
		mov = ft_split_move_to_back(args, *i);
		tmp = ft_strdup(&args[*i + mov][1]);
		free(args[*i + mov]);
		args[*i + mov] = tmp;
		d->fd_io[1] = open(args[*i + mov], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		ft_split_delete_last(args);
		d->file_o++;
		*i = 0;
		return (1);
	}
	return (0);
}

/* Handle output redirection markers for each piped command. */
void	handle_output(t_data *d, char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (handle_o(d, args, &i))
			continue ;
		else if (handle_joined_o(d, args, &i))
			continue ;
		else if (handle_o2(d, args, &i))
			continue ;
		else if (handle_joined_o2(d, args, &i))
			continue ;
		i++;
	}
	if (d->file_o > 0)
		cmd_out_redirect(d);
}
