/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:47:00 by kbrauer           #+#    #+#             */
/*   Updated: 2023/12/21 14:12:52 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minitalk.h"

int	g_var_c = 1;

void	ex_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit (1);
}

int	send_signal(int pid, int c)
{
	int	i;
	int	vv;

	i = 8;
	while (i != 0)
	{
		if (c % 2 == 0 && kill(pid, SIGUSR1) == -1)
			ex_error(ERROR3);
		else if (c % 2 == 1 && kill(pid, SIGUSR2) == -1)
			ex_error(ERROR3);
		c = c >> 1;
		vv = 0;
		i--;
		g_var_c = 0;
		while (g_var_c == 0 && vv < 20000)
			(usleep(100), vv++);
		if (vv == 20000)
			ex_error(ERROR5);
	}
	return (0);
}

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	ucontext = NULL;
	info = NULL;
	if (sig == SIGUSR2)
	{
		ft_printf("\nMessage recieved\n");
		exit (1);
	}
	g_var_c = 1;
}

int	check_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	if (i == 6 || i == 7)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	action;
	int					i;

	if (argc != 3)
		ex_error(ERROR1);
	if (check_pid(argv[1]))
		ex_error(ERROR2);
	pid = ft_atoi(argv[1]);
	action.sa_sigaction = &handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	if (sigaction(SIGUSR1, &action, NULL) == -1)
		ex_error(ERROR4);
	if (sigaction(SIGUSR2, &action, NULL) == -1)
		ex_error(ERROR4);
	i = 0;
	while (argv[2][i])
	{
		send_signal(pid, argv[2][i]);
		i++;
	}
	send_signal(pid, argv[2][i]);
	return (0);
}
