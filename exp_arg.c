/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 07:26:37 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/22 15:31:02 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	search_var(t_data *d, int k)
{
	int		i;
	char	*arg_tmp;
	char	*env_tmp;

	arg_tmp = ft_strdup(d->cmd[k]);
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

static char	*trim_exp_sing_quot(char *s)
{
	char	*tmp;
	char	*add;

	if (*(ft_strchr(s, '=') + 1) == '\'' && s[ft_strlen(s) - 1] == '\'')
	{
		s[ft_strlen(s) - 1] = '\0';
		*(ft_strchr(s, '=') + 1) = '\0';
		tmp = ft_strdup(s);
		add = ft_strdup(ft_strchr(s, '=') + 2);
		free(s);
		s = ft_strjoin(tmp, add);
		free(tmp);
		free(add);
		return (s);
	}
	return (s);
}

static char	*trim_exp_dbl_quot(char *s)
{
	char	*tmp;
	char	*add;

	if (*(ft_strchr(s, '=') + 1) == '\"' && s[ft_strlen(s) - 1] == '\"')
	{
		s[ft_strlen(s) - 1] = '\0';
		*(ft_strchr(s, '=') + 1) = '\0';
		tmp = ft_strdup(s);
		add = ft_strdup(ft_strchr(s, '=') + 2);
		free(s);
		s = ft_strjoin(tmp, add);
		free(tmp);
		free(add);
		return (s);
	}
	else if (*(ft_strchr(s, '=') + 1) == '\'' && s[ft_strlen(s) - 1] == '\'')
	{
		s = trim_exp_sing_quot(s);
		return (s);
	}
	return (s);
}

void	ft_exportarg(t_data *d)
{
	int		i;

	i = 1;
	while (d->cmd[i] && ft_strcmp(d->cmd[i], "|") != 0)
	{
		d->cmd[i] = trim_exp_dbl_quot(d->cmd[i]);
		printf("%s\n", d->cmd[i]);
		if (!ft_strchr(d->cmd[i], '='))
			return ;
		if (search_var(d, i) < 0)
			d->envv = ft_addstrstrarr(d->envv, d->cmd[i]);
		else
			replace_str(d->envv, search_var(d, i), d->cmd[i]);
		i++;
	}
}
