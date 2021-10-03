# include <signal.h>
# include "minishell.h"

struct sigaction	sa_sig;

sa_sig.sa_flags = SA_SIGINFO;
sa_sig.sa_sigaction = sig_handl;

if (sigaction(SIGINT, &sa_sig, NULL) == -1)
	ft_terror("SIGACTION ERROR\n");
if (sigaction(SIGQUIT, &sa_sig, NULL) == -1)
	ft_terror("SIGACTION ERROR\n");
if (sigaction(SIGUSR1, &sa_sig, NULL) == -1)
	ft_terror("SIGACTION ERROR\n");

static void	sig_handl(int signum, siginfo_t *info, void *unused)
{
	(void)unused;
	(void)info;
	if (signum == SIGINT)
	{
		printf("CTRL+C RECEIVED");
	}
	else if (signum == SIGQUIT)
	{
		printf("CTRL+\\ RECEIVED");
	}
	else if (signum == SIGUSR1)
	{
		printf("CTRL+D RECEIVED");
	}
}

int	execute(char **args)
{
	if (NULL == args[0])
		return (0);
	else if (ft_strncmp(args[0], "cd", 100) == 0)
		return (ft_cd(args));
	else if (ft_strncmp(args[0], "pwd", 100) == 0)
		return (ft_pwd(args));
	else if (ft_strncmp(args[0], "export", 100) == 0)
		return (ft_export(args));
	else if (ft_strncmp(args[0], "unset", 100) == 0)
		return (ft_unset(args));
	else if (ft_strncmp(args[0], "env", 100) == 0)
		return (ft_env(args));
	else if (ft_strncmp(args[0], "exit", 100) == 0)
		return (ft_exit(args));
	else
		return (ft_interpret(args));
}

int	ft_cd(char **args)
{
	if (NULL == args[1])
		printf("Argument needed for \"cd\"\n");
	else
	{
		if (chdir(args[1]) != 0)
			printf("Unknown path for \"cd\"\n");
	}
	return (1);
}

int	ft_exit(char **args)
{
	return (0);
}
