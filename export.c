/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:10:01 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/09 13:32:35 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sort_strarr(char **arr, int size)
{
	int		i;
	int		swap;
	char	*tmp;

	i = 0;
	swap = 1;
	while (swap == 1)
	{
		swap = 0;
		i = 0;
		while (i < size - 1)
		{
			if (ft_strcmp(arr[i], arr[i + 1]) > 0)
			{
				tmp = ft_strdup(arr[i]);
				free(arr[i]);
				arr[i] = ft_strdup(arr[i + 1]);
				free(arr[i + 1]);
				arr[i + 1] = ft_strdup(tmp);
				free(tmp);
				swap = 1;
			}
			i++;
		}
	}
}

static void	sort_print(t_data *d)
{
	char	**copy_env;
	int		i;

	i = 0;
	copy_env = ft_strarrdup(d->envv);
	sort_strarr(copy_env, ft_strarrlen(copy_env));
	while (copy_env[i])
		printf("declare -x %s\n", copy_env[i++]);
	ft_split_free(copy_env);
}

void	ft_export(t_data *d)
{
	if (d->cmd[1] == NULL)
		sort_print(d);
}
