/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:30:33 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/11 16:44:40 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Replace redirection signs and everything after '>' with ' ' */
void	rm_redirection_sgn(char *line, char c)
{
	int	i;

	if (!line)
		return ;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '<')
			line[i] = (unsigned char)c;
		if (line[i] == '>')
		{
			while (line[i])
				line[i++] = (unsigned char)c;
			break ;
		}
		i++;
	}
}

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
	d->cmd = ft_split(d->line, ' ');
	if (!d->cmd || !d->cmd[0])
		perror("No command passed");
	rm_redirection_sgn(d->line, ' ');
	d->cmd_pipe = ft_split(d->line, '|');
	expand_env(d);
	check_line(d);
	pipe_init(d);
	execute(d);
	if (d->fname_i2)
		unlink(d->fname_i2);
	ft_split_free(d->cmd);
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
		d.line = readline(GR "shell:>$ " CL);
		if (!d.line)
			ft_exit(&d);
		init_data(&d);
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
	free_memory(&d);
	return (0);
}
