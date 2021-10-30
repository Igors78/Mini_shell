/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:10:01 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/30 15:13:10 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

static void	add_quotes(char **arr)
{
	char	*add1;
	char	*add2;
	int		i;

	i = 0;
	while (arr[i])
	{
		*(ft_strchr(arr[i], '=')) = '\0';
		add1 = ft_strjoin(arr[i], "=\"");
		add2 = ft_strjoin(add1, &arr[i][ft_strlen(arr[i]) + 1]);
		free(arr[i]);
		arr[i] = ft_strjoin(add2, "\"");
		free(add1);
		free(add2);
		i++;
	}
}

static int	sort_print(t_data *d)
{
	char	**copy_env;
	int		i;

	i = 0;
	copy_env = ft_strarrdup(d->envv);
	sort_strarr(copy_env, ft_strarrlen(copy_env));
	add_quotes(copy_env);
	while (copy_env[i])
		printf("declare -x %s\n", copy_env[i++]);
	ft_split_free(copy_env);
	return (EXIT_SUCCESS);
}

static int	check_exportarg(char *s)
{
	if (!s)
		return (-1);
	if (ft_isdigit(s[0]) || s[0] == '=' || s[0] == '?')
	{
		printf("bash: export: `%s': not a valid identifier\n", s);
		return (-1);
	}
	return (0);
}

void	ft_export(t_data *d, char **args)
{
	if (d->n_pipe == 0)
	{
		handle_input(d, args);
		handle_output(d, args);
	}
	if (!args[1])
		exit(sort_print(d));
	else
	{
		if (d->n_pipe > 0)
		{
			d->exit_status = 0;
			return ;
		}
		if (check_exportarg(args[1]))
		{
			d->exit_status = 1;
			return ;
		}
		ft_exportarg(d, args);
	}
}
