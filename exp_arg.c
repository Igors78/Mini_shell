/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 07:26:37 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/10 16:48:22 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	search_var(t_data *d)
{
	int		i;
	char	*arg_tmp;
	char	*env_tmp;

	arg_tmp = ft_strdup(d->cmd[1]);
	*(ft_strchr(arg_tmp, '=')) = '\0';
	i = 0;
	while (d->envv[i])
	{
		env_tmp = ft_strdup(d->envv[i]);
		*(ft_strchr(env_tmp, '=')) = '\0';
		if (ft_strcmp(env_tmp, arg_tmp) == 0)
		{
			free(arg_tmp);
			free(env_tmp);
			return (i);
		}
		free(env_tmp);
		i++;
	}
	free(arg_tmp);
	return (-1);
}

static void	replace_str(char **arr, int index, char *str)
{
	free(arr[index]);
	arr[index] = ft_strdup(str);
}

void	ft_exportarg(t_data *d)
{
	if (!ft_strchr(d->cmd[1], '='))
		return ;
	if (search_var(d) < 0)
		d->envv = ft_addstrstrarr(d->envv, d->cmd[1]);
	else
		replace_str(d->envv, search_var(d), d->cmd[1]);
}
