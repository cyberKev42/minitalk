/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:47:06 by kbrauer           #+#    #+#             */
/*   Updated: 2023/12/21 14:08:02 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"

int	g_var_s = 0;

void	ex_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static char	c = 0;
	static int	i = 0;
	static int	pid = 0;

	ucontext = NULL;
	g_var_s = 1;
	if (info->si_pid != pid)
		(ft_printf("\n"), c = 0, i = 0, pid = info->si_pid);
	if (sig == SIGUSR2)
		c = c + (1 << i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		if (c == '\0')
		{
			if (kill(info->si_pid, SIGUSR2) == -1)
				ex_error(ERROR3);
			g_var_s = 0;
		}
		i = 0;
		c = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		ex_error(ERROR3);
}

int	main(void)
{
	struct sigaction	action;

	ft_printf("The PID of this server is %d\n", getpid());
	action.sa_sigaction = &handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		ex_error(ERROR4);
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		ex_error(ERROR4);
	while (1)
	{
		pause();
	}
}
