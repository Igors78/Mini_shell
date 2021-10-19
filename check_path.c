/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 13:48:39 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/19 13:31:52 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	if (d->pid == 0)
		printf("%s: command not found\n", cmd);
	ft_split_free(split_path);
}
