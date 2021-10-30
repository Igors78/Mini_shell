/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarut <mbarut@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 11:40:34 by ioleinik          #+#    #+#             */
/*   Updated: 2021/10/30 14:30:06 by mbarut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sig_handl(int signum, siginfo_t *info, void *unused)
{
	(void)unused;
	(void)info;
	if (signum == SIGINT)
	{
		printf("\b\b  \n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (signum == SIGQUIT)
	{
		printf("\b\b  \b\b");
	}
}

void	init_sig(void)
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
