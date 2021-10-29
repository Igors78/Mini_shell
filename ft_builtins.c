/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:24:10 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/29 14:58:48 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_n(char *s)
{
	int		i;
	size_t	cnt;

	i = 1;
	cnt = 1;
	if (s[0] == '-')
	{
		while (s[i])
		{
			if (s[i] == 'n')
				cnt++;
			i++;
		}
		if (cnt == ft_strlen(s))
			return (1);
	}
	return (0);
}

void	ft_echo(t_data *d, char **args)
{
	int	i;
	int	nl;

	i = 1;
	nl = 1;
	while (args[i])
	{
		if (i == 1 && check_n(args[i]))
		{
			nl = 0;
			i++;
			while (args[i] && check_n(args[i]))
				i++;
			if (!args[i])
				exit(EXIT_SUCCESS);
		}
		if (args[i + 1])
		{
			ft_putstr_fd(args[i], d->fd_io[1]);
			ft_putstr_fd(" ", d->fd_io[1]);
		}
		else
			ft_putstr_fd(args[i], d->fd_io[1]);
		i++;
	}
	if (nl == 1)
		ft_putstr_fd("\n", d->fd_io[1]);
	ft_split_free(args);
	exit(EXIT_SUCCESS);
}

void	ft_env(t_data *d, char **args)
{
	int	i;

	i = 0;
	if (args[1])
	{
		printf("env: `%s\': No such file or directory\n", args[1]);
		exit(127);
	}
	else
	{
		while (d->envv[i])
		{
			printf("%s\n", d->envv[i]);
			i++;
		}
		exit(EXIT_SUCCESS);
	}
}

void	ft_exit(char **args)
{
	char	*tmp;
	int		ret;

	if (args && args[1])
	{
		tmp = args[1];
		ret = ft_atoi(tmp);
		exit(ret);
	}
	else
		exit(EXIT_SUCCESS);
}

void	ft_pwd(t_data *d, char **args)
{
	char	cwd[10000];

	(void)args;
	(void)d;
	if (getcwd(cwd, sizeof(cwd)))
		printf("%s\n", cwd);
	exit(EXIT_SUCCESS);
}
