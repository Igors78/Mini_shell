/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:30:33 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/02 17:04:53 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	pid_t		pid;
	char		**nargv;
	extern char	**environ;
	char		*line;
	int			i;
	static char	command[10000] = "/bin/";

	i = 0;
	line = readline(">$ ");
	nargv = ft_split(line, ' ');
	ft_strlcat(command, nargv[0], 10000);
	pid = fork();
	if (pid == -1)
		ft_terror("Fork error");
	if (pid == 0)
	{
		execve(command, nargv, environ);
		ft_terror("Exec error");
	}
	waitpid(pid, NULL, 0);
	while (nargv[i])
		free(nargv[i++]);
	free(nargv);
	free(line);
	return (0);
}
