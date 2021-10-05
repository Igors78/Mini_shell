/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioleinik <ioleinik@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:16:46 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/05 13:03:41 by ioleinik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>

# define RD	"\x1b[31m"
# define GR	"\x1b[32m"
# define CL	"\x1b[0m"

typedef struct s_data
{
	char				**envv;
	char				*line;
	struct sigaction	sa_sig;
	char				**cmd;
	char				*path;
	pid_t				pid;
	int					status;
}				t_data;

void	execute(t_data *d);
void	ft_interpret(t_data *d);
void	ft_exit(t_data *d);
void	ft_env(t_data *d);

#endif