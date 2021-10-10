/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:30:33 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/10 15:24:55 by ioleinik         ###   ########.fr       */
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
		rl_replace_line("", 0);
		rl_redisplay();
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
	d->path = NULL;
	d->pid = -42;
}

static void	init_sig(void)
{
	struct sigaction	sa_sig;

	sa_sig.sa_flags = SA_SIGINFO;
	sa_sig.sa_sigaction = sig_handl;
	sigemptyset(&sa_sig.sa_mask);
	if (sigaction(SIGINT, &sa_sig, NULL) == -1)
		perror("SIGACTION ERROR\n");
	if (sigaction(SIGQUIT, &sa_sig, NULL) == -1)
		perror("SIGACTION ERROR\n");
}

int	main(int argc, char **argv, char **environ)
{
	t_data	d;

	(void)argc;
	(void)argv;
	d.envv = ft_strarrdup(environ);
	d.line = NULL;
	init_sig();
	while (1)
	{
		init_data(&d);
		d.line = readline(GR "shell:>$ " CL);
		if (!d.line)
			ft_exit(&d);
		if (!d.line[0])
			continue ;
		else
		{
			dispatch(&d);
			if (d.pid >= 0)
				waitpid(d.pid, NULL, 0);
			free(d.line);
		}
	}
	return (0);
}
