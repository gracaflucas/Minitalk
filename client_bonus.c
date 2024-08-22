/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:22:51 by lufiguei          #+#    #+#             */
/*   Updated: 2024/07/12 13:22:52 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void		sig_handler(int sig);
static void	send(int id, char c);

int	g_received;

int	main(int argc, char **argv)
{
	int		i;
	int		pid;
	char	*str;

	if (argc != 3)
	{
		ft_printf("Wrong Command line argument! try ");
		ft_printf("\"./client\" \"PID\" \"String\"\n");
		return (1);
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	str = argv[2];
	if (pid <= 0)
		return (ft_printf("Incorrect PID\n"));
	while (str[i] != '\0')
	{
		send(pid, str[i]);
		i++;
	}
	send(pid, '\0');
	while (g_received == 0)
		pause();
	return (0);
}

void	sig_handler(int sig)
{
	if (sig == SIGUSR2)
	{
		g_received = 1;
		ft_printf("Message received.\n");
	}
	else if (sig == SIGUSR1)
		g_received = 1;
}

static void	send(int id, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		g_received = 0;
		if (c >> bit & 1)
		{
			if (kill(id, SIGUSR2) == -1)
				exit(ft_printf("Failed to send signal to %d\n", id));
		}
		else
		{
			if (kill(id, SIGUSR1) == -1)
				exit(ft_printf("Failed to send signal to %d\n", id));
		}
		bit--;
		while (g_received == 0)
			pause();
	}
}
