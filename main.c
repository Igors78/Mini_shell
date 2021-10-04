/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:30:33 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/04 13:27:49 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	cmd_exec(char *line, size_t	n_cmd, char **environ)
{
	char		***cmd;
	char		*tmp;
	pid_t		pid;
	int			ret;

	cmd = ft_calloc(n_cmd, sizeof(char **));
	cmd[0] = ft_split(line, ' ');
	tmp = cmd[0][0];
	cmd[0][0] = ft_strjoin("/bin/", cmd[0][0]);
	pid = fork();
	if (pid == -1)
		perror("fork() failed");
	if (pid == 0)
	{
		ret = execve(cmd[0][0], cmd[0], environ);
		if (ret == -1)
		{
			ft_split_free(cmd[0]);
			free(tmp);
			perror("execve() failed");
			exit(EXIT_FAILURE);
		}
	}
	return (pid);
}

int	main(void)
{
	extern char	**environ;
	char		*line;

	while (1)
	{
		line = readline(">$ ");
		if (!line || !line[0])
			break ;
		add_history(line);
		waitpid(cmd_exec(line, 1, environ), NULL, 0);
		free(line);
	}
	rl_clear_history();
	rl_redisplay();		// I dunno what this is
	rl_on_new_line();	// I dunno what this is
	return (0);
}
