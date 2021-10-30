/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:30:33 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/30 10:05:37 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	dispatch(t_data	*d)
{
	add_history(d->line);
	d->cmd = ft_splitarg(d->line, ' ');
	if (!d->cmd || !d->cmd[0])
		perror("No command passed");
	d->cmd_pipe = ft_splitarg(d->line, '|');
	pipe_init(d);
	execute(d);
	pipe_end(d);
	unlink("_tmp");
	ft_split_free(d->cmd_pipe);
	ft_split_free(d->cmd);
}

static void	dispatch_help(t_data *d)
{
	dispatch(d);
	if (d->pid >= 0)
		waitpid(d->pid, NULL, 0);
	if (d->saved_stdout)
	{
		dup2(d->saved_stdout, STDOUT_FILENO);
		close(d->saved_stdout);
	}
	free(d->line);
}

static int	check_space(char *s)
{
	int		i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			cnt++;
		i++;
	}
	if (cnt == ft_strlen(s))
		return (1);
	return (0);
}

int	main(void)
{
	t_data		d;
	extern char	**environ;

	d.envv = ft_strarrdup(environ);
	d.exit_status = 0;
	while (1)
	{
		init_data(&d);
		d.line = readline(GR "shell:>$ " CL);
		if (!d.line)
			ft_exit(NULL);
		handle_comments(&d);
		if (!d.line[0] || check_space(d.line))
			continue ;
		else
			dispatch_help(&d);
	}
	return (0);
}
