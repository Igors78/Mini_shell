/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:48:39 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/30 15:39:52 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	check_path(t_data *d, char *cmd)
{
	char		**split_path;
	int			i;
	struct stat	st;
	char		*check;
	char		*addslash;

	i = 0;
	split_path = ft_split(ft_getenv(d, "PATH"), ':');
	while (split_path[i])
	{
		addslash = ft_strjoin(split_path[i++], "/");
		check = ft_strjoin(addslash, cmd);
		free(addslash);
		if (!stat(check, &st))
		{
			d->path = check;
			ft_split_free(split_path);
			return ;
		}
		else
			free(check);
	}
	printf("%s: command not found\n", cmd);
	ft_split_free(split_path);
}
