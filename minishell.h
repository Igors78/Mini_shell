/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 12:16:46 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/30 13:15:27 by mbarut           ###   ########.fr       */
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
# include <limits.h>

# define RD	"\x1b[31m"
# define GR	"\x1b[32m"
# define CL	"\x1b[0m"

// n_pipe;// number of subtrings that are "|"
// file_i;// >=1 if string array contains "<", =0 otherwise
// file_o;// >=1 if string array contains ">", =0 otherwise
// file_i2;// >=1 if string array contains "<<", =0 otherwise (see here docs)
// file_o2;// >=1 if string array contains ">>", =0 otherwise
// fd_io[2];// file descriptors for input/output
// *fd_pipe;// file descriptors for pipes
// *pos_pipe;// array holding the positions of pipes
// flag_builtin;// if =1, spawning a new process is skipped
// saved_stdout;// it is necessary to dup() stdout to a variable
//					when there is output redirection without fork() (builtins)
// flag_sq;		// flag for single quotes when handling comments
// flag_dq;		// flag for double quotes when handling comments

typedef struct s_data
{
	char				**envv;
	char				*line;
	char				**cmd;
	char				**cmd_pipe;
	char				*path;
	pid_t				pid;
	int					n_pipe;
	int					file_i;
	int					file_o;
	int					file_i2;
	int					file_o2;
	int					fd_io[2];
	int					*fd_pipe;
	int					*pos_pipe;
	int					exit_status;
	int					flag_builtin;
	int					saved_stdout;
	int					i;
	int					q;
	int					qq;
	char				*buf;
	int					flag_sq;
	int					flag_dq;
	int					flag_forked;
}				t_data;

void	init_data(t_data *d);
void	execute(t_data *d);
void	ft_exit(char **args);
void	expand_env(t_data *d, char **cmd);
void	ft_export(t_data *d, char **args);
char	**ft_strarrdup(char **src);
int		ft_strarrlen(char **src);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_exportarg(t_data *d, char **args);
void	free_memory(t_data *d);

char	*ft_getenv(t_data *d, char *str);
void	check_path(t_data *d, char *cmd);
char	**ft_splitarg(char const *s, char c);
void	sig_handl(int signum, siginfo_t *info, void *unused);
void	init_sig(void);
char	*chk_sing_quo(t_data *d, char *s);
char	*chk_exp(t_data *d, char *s);
void	put_strarr(char **arr);
char	*trim_quot(char *s);

void	ft_split_delete_last(char **args);
int		ft_split_move_to_back(char **args, int pos);

void	handle_input(t_data *d, char **args);
void	handle_output(t_data *d, char **args);
int		handle_fork(t_data *d, int *i, int *j);
void	handle_exec(t_data *d, int i);
void	handle_pipe(t_data *d, int i, int j);
void	handle_builtins(t_data *d, char **args);

int		is_builtin(char *cmd);
int		is_forkable(char **args, int pos_exe);

void	pipe_end(t_data *d);
void	pipe_init(t_data *d);

/* error handlers */
void	fork_failed(t_data *d);
void	open_failed(t_data *d);
void	dup_failed(t_data *d);
void	pipe_failed(t_data *d);
void	write_failed(t_data *d);

char	*check_env(t_data *d, char *s);
char	*parse_env(t_data *d, char *s);
char	*stick_back(char **spl);
char	*glue_back(char **spl);
void	ft_echo(t_data *d, char **args);
void	ft_env(t_data *d, char **args);
void	ft_pwd(t_data *d, char **args);
void	handle_buck(t_data *d, char *s);

void	handle_comments(t_data *d);
void	cond_ch_put(t_data *d, char **args, int i);
void	check_access(t_data *d, char **args);
int		handle_joined_i(t_data *d, char **args, int *i);
void	cmd_out_redirect(t_data *d);

#endif