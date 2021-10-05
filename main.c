/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:30:33 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/05 13:02:06 by ioleinik         ###   ########.fr       */
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
		printf(GR ">$ " CL);
	}
	else if (signum == SIGQUIT)
	{
		printf("\b\b  \b\b");
	}
}

static void	cmd_exec(t_data	*d)
{
	d->cmd = ft_split(d->line, ' ');
	if (!d->cmd || !d->cmd[0])
		perror("No command passed");
	if (ft_strncmp(d->cmd[0], "exit", 5) == 0 && ft_strlen(d->cmd[0]) == 4)
	{
		ft_exit(d);
		return ;
	}
	if (ft_strncmp(d->cmd[0], "env", 4) == 0 && ft_strlen(d->cmd[0]) == 3)
		ft_env(d);
	d->path = ft_strjoin("/bin/", d->cmd[0]);
	d->pid = fork();
	if (d->pid == -1)
		perror("fork() failed");
	if (d->pid == 0)
	{
		execute(d);
		if (d->status)
		{
			ft_split_free(d->cmd);
			free(d->path);
		}
	}
}

static void	init_data(t_data *d)
{
	extern char	**environ;

	d->sa_sig.sa_flags = SA_SIGINFO;
	d->sa_sig.sa_sigaction = sig_handl;
	if (sigaction(SIGINT, &d->sa_sig, NULL) == -1)
		perror("SIGACTION ERROR\n");
	if (sigaction(SIGQUIT, &d->sa_sig, NULL) == -1)
		perror("SIGACTION ERROR\n");
	d->status = 0;
	d->envv = environ;
	d->line = NULL;
}

int	main(void)
{
	t_data	d;

	d.status = 0;
	while (!d.status)
	{
		init_data(&d);
		d.line = readline(GR ">$ " CL);
		if (!d.line)
			break ;
		else if (!d.line[0])
			continue ;
		else
		{
			add_history(d.line);
			cmd_exec(&d);
			waitpid(d.pid, NULL, 0);
			free(d.line);
		}
	}
	rl_clear_history();
	rl_redisplay();
	rl_on_new_line();
	return (0);
}
