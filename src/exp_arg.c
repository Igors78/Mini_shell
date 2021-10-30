/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 07:26:37 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/30 15:26:24 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	search_var(t_data *d, char **args, int k)
{
	int		i;
	char	*arg_tmp;
	char	*env_tmp;

	arg_tmp = ft_strdup(args[k]);
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

void	ft_exportarg(t_data *d, char **args)
{
	int		i;

	i = 1;
	while (args[i])
	{
		if (!ft_strchr(args[i], '='))
			return ;
		args[i] = trim_exp_dbl_quot(args[i]);
		if (search_var(d, args, i) < 0)
			d->envv = ft_addstrstrarr(d->envv, args[i]);
		else
			replace_str(d->envv, search_var(d, args, i), args[i]);
		i++;
	}
}
