/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:30:33 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/26 16:07:43 by mbarut           ###   ########.fr       */
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

int	main(void)
{
	t_data		d;
	extern char	**environ;

	d.envv = ft_strarrdup(environ);
	d.exit_status = 0; // (!) assuming minishell does not inherit the exit code from the environment
	while (1)
	{
		init_data(&d);
		d.line = readline(GR "shell:>$ " CL);
		if (!d.line)
			ft_exit(NULL);
		if (!d.line[0])
			continue ;
		else
		{
			dispatch(&d);
			if (d.pid >= 0)
				waitpid(d.pid, NULL, 0);
			if (d.saved_stdout)
			{
				dup2(d.saved_stdout, STDOUT_FILENO);
				close(d.saved_stdout);
			}
			free(d.line);
		}
	}
	return (0);
}
