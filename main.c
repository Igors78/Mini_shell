/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:30:33 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/19 13:45:35 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* Helper function to make rm_redirection_sgn() shorter */
int	ignore_quotes(char *line, int i, char c)
{
	while (line[i] != c)
		i++;
	return (i);
}

/* Replace redirection signs and everything after '>' with ' ' */
void	rm_redirection_sgn(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\"' && ft_strchr(&line[i + 1], '\"') && i++)
			i = ignore_quotes(line, i, '\"');
		if (line[i] == '\'' && ft_strchr(&line[i + 1], '\'') && i++)
			i = ignore_quotes(line, i, '\'');
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

static void	dispatch(t_data	*d)
{
	add_history(d->line);
	d->cmd = ft_splitarg(d->line, ' ');
	if (!d->cmd || !d->cmd[0])
		perror("No command passed");
	rm_redirection_sgn(d->line, ' ');
	//expand_env(d);
	d->cmd_pipe = ft_splitarg(d->line, '|');
	check_line(d);
	pipe_init(d);
	execute(d);
	if (d->fname_i2)
		unlink(d->fname_i2);
	ft_split_free(d->cmd);
}

int	main(int argc, char **argv, char **environ)
{
	t_data	d;

	(void)argc;
	(void)argv;
	d.envv = ft_strarrdup(environ);
	d.line = NULL;
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
	free_memory(&d);
	return (0);
}
