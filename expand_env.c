/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:04:02 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/11 14:04:17 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_env(t_data *d)
{
	int		i;
	char	*tmp;

	i = 0;
	while (d->cmd[i])
	{
		if (d->cmd[i][0] == '$')
		{
			if (d->cmd[i][1] == '{'
				&& d->cmd[i][ft_strlen(d->cmd[i]) - 1] == '}')
			{
				d->cmd[i][ft_strlen(d->cmd[i]) - 1] = '\0';
				tmp = ft_getenv(d, &d->cmd[i][2]);
			}
			else
				tmp = ft_getenv(d, &d->cmd[i][1]);
			if (!tmp)
				return ;
			free(d->cmd[i]);
			d->cmd[i] = ft_strdup(tmp);
		}
		i++;
	}
}
