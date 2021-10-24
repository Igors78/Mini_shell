/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 20:24:10 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/24 22:53:31 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_data *d, char **args)
{
	int	i;
	int	nl;

	i = 1;
	nl = 1;
	while (args[i])
	{
		if (i == 1 && ft_strcmp(args[i], "-n") == 0 && ft_strlen(args[i]) == 2)
		{
			nl = 0;
			if (args[i + 1])
				i++;
			else
				break ;
		}
		printf("%s ", args[i]);
		i++;
	}
	printf("\b");
	if (nl == 1)
		printf("\n");
	d->exit_status = 0;
}

void	ft_env(t_data *d, char **args)
{
	int	i;

	i = 1;
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
