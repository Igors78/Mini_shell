/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:16:46 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/17 16:28:37 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <sys/stat.h>
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
	char				**cmd;
	char				**cmd_pipe;
	char				*path;
	pid_t				pid;
	char				*tmp; 		// tmp file for the here document (<<)
	int					n;			// number of substrings from split()
	int					n_pipe;		// number of subtrings that are "|"
	int 				pos_p1;		// position of the first "|" in string array
	int					pos_p2;		// position of the last "|" in string array
	int					pos_i;		// position of the input direction marker "<" or "<<" in string array
	int					isjoined_i;	// >=1 if string array contains conjoined input redirection, e.g. <input or <<EOF
	int					isjoined_o;	// >=1 if string array contains conjoined output redirection, e.g. >output or >>output
	int					pos_o;		// position of the output direction marker ">" or ">>" in string array
	int					pos_x;		// position of the executable command in string array. =-1 if the executable command is not accessible
	int					file_i;		// >=1 if string array contains "<", =0 otherwise
	int					file_o;		// >=1 if string array contains ">", =0 otherwise
	int					file_i2;	// >=1 if string array contains "<<", =0 otherwise (see here documents)
	char				*fname_i2;	// name of the temporary file for here documents
	int					file_o2;	// >=1 if string array contains ">>", =0 otherwise
	int					fvalid;		// =1 if the input/output files (if exist) are accessible =0 otherwise
	int					xvalid;		// =1 if the executable commands (if exist) are accessible =0 otherwise
	int					fd_io[2];	// file descriptors for input/output
	int					*fd_pipe;	// file descriptors for pipes
	int					*pos_pipe;	// array holding the positions of pipes
}				t_data;

void	init_data(t_data *d);
void	execute(t_data *d);
void	ft_exit(t_data *d);
void	ft_env(t_data *d);
void	expand_env(t_data *d, char **cmd);
void	ft_export(t_data *d);
char	**ft_strarrdup(char **src);
int		ft_strarrlen(char **src);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_exportarg(t_data *d);
void	free_memory(t_data *d);

char	*ft_getenv(t_data *d, char *str);
void	check_path(t_data *d, char *cmd);
char	**ft_splitarg(char const *s, char c);
void	sig_handl(int signum, siginfo_t *info, void *unused);
void	init_sig(void);
int		chk_sing_quo(t_data *d, char **spl, int *i, char *tmp);
int		chk_curl_br(t_data *d, char **spl, int *i, char *tmp);

/* Piping and redirection */

enum	pos_pipe {
	pipe_first,
	pipe_last
};

void	check_redirection(t_data *d);
void	check_io(t_data *d);
void	check_x(t_data *d);
void	check_line(t_data *d);
int		is_builtin(t_data *d);

void	pipe_end(t_data *d);
void	pipe_init(t_data *d);

void	fork_failed(t_data *d);
void	open_failed(void);
void	x_access_failed(t_data *d);

void	cmd_x(t_data *d);
void	cmd_out(t_data *d);

#endif