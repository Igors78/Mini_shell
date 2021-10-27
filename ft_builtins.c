/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:24:10 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/27 17:58:00 by ioleinik         ###   ########.fr       */
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
		if (i == 1 && check_n(args[i++]))
		{
			nl = 0;
			while (args[i] && check_n(args[i]))
				i++;
			if (!args[i])
				return ;
		}
		if (args[i + 1])
			printf("%s ", args[i]);
		else
			printf("%s", args[i]);
		i++;
	}
	if (nl == 1)
		printf("\n");
	d->exit_status = 0;
}

void	ft_env(t_data *d, char **args)
{
	int	i;

	i = 0;
	if (args[1])
	{
		printf("env: `%s\': No such file or directory\n", args[1]);
		d->exit_status = 127;
	}
	else
	{
		while (d->envv[i])
		{
			printf("%s\n", d->envv[i]);
			i++;
		}
		d->exit_status = 0;
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
	if (getcwd(cwd, sizeof(cwd)))
		printf("%s\n", cwd);
	d->exit_status = 0;
}
