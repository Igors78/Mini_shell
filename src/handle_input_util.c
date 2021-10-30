/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 09:23:38 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/30 14:03:40 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* Check if input file is accessible. */
void	check_access(t_data *d, char **args)
{
	int	i;

	if (d->file_i > 0)
	{
		i = 0;
		while (args[i])
			i++;
		if (access(args[i - 1], F_OK) != 0 || access(args[i - 1], R_OK) != 0)
		{
			ft_putstr_fd(args[i - 1], STDERR_FILENO);
			perror(" cannot be accessed");
		}
	}
}

//Handle multiple, position-independent input redirection with joined markers.
int	handle_joined_i(t_data *d, char **args, int *i)
{
	char	*tmp;
	int		mov;

	if (args[*i][0] == '<' && args[*i][1] != '<')
	{
		if (d->file_i > 0 && d->file_i--)
			ft_split_delete_last(args);
		mov = ft_split_move_to_back(args, *i);
		tmp = ft_strdup(&args[*i + mov][1]);
		free(args[*i + mov]);
		args[*i + mov] = tmp;
		d->file_i++;
		*i = 0;
		return (1);
	}
	return (0);
}
