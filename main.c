/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:30:33 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/09 18:55:40 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sig_handl(int signum, siginfo_t *info, void *unused)
{
	(void)unused;
	(void)info;
	if (signum == SIGINT)
	{
		printf("\b\b  \n");
		printf(GR "shell:>$ " CL);
	}
	else if (signum == SIGQUIT)
	{
		printf("\b\b  \b\b");
	}
}

static void	dispatch(t_data	*d)
{
	add_history(d->line);
	if (!ft_strchr(d->line, '|') && !ft_strchr(d->line, '<')
		&& !ft_strchr(d->line, '>'))
	{
		d->cmd = ft_split(d->line, ' ');
		if (!d->cmd || !d->cmd[0])
			perror("No command passed");
		expand_env(d);
		execute(d);
	}
}

static void	init_data(t_data *d)
{
	d->sa_sig.sa_flags = SA_SIGINFO;
	d->sa_sig.sa_sigaction = sig_handl;
	if (sigaction(SIGINT, &d->sa_sig, NULL) == -1)
		perror("SIGACTION ERROR\n");
	if (sigaction(SIGQUIT, &d->sa_sig, NULL) == -1)
		perror("SIGACTION ERROR\n");
	d->path = NULL;
	d->line = NULL;
	d->pid = -42;
}

static void	ctrl_d(t_data *d)
{
	free(d->line);
	rl_clear_history();
	exit (0);
}

int	main(int argc, char **argv, char **environ)
{
	t_data	d;

	(void)argc;
	(void)argv;
	d.envv = environ;
	while (1)
	{
		init_data(&d);
		d.line = readline(GR "shell:>$ " CL);
		if (!d.line)
			ctrl_d(&d);
		if (!d.line[0])
			continue ;
		else
		{
			dispatch(&d);
			if (d.pid >= 0)
				waitpid(d.pid, NULL, 0);
			free(d.line);
		}
		if (!d.line)
			ctrl_d(&d);
	}
	return (0);
}
