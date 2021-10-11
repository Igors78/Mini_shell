/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:00:27 by mbarut            #+#    #+#             */
/*   Updated: 2021/10/11 14:00:49 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(t_data *d, char *str)
{
	int		i;
	char	*env_tmp;

	i = 0;
	while (d->envv[i])
	{
		env_tmp = ft_strdup(d->envv[i]);
		*(ft_strchr(env_tmp, '=')) = '\0';
		if (ft_strcmp(env_tmp, str) == 0)
		{
			free(env_tmp);
			return (ft_strchr(d->envv[i], '=') + 1);
		}
		free(env_tmp);
		i++;
	}
	return (NULL);
}
