/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:22:32 by lufiguei          #+#    #+#             */
/*   Updated: 2024/07/12 13:22:34 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int sig, siginfo_t *info, void *context);
static void	append_char(t_list **list, char c);
static void	pfree_list(t_list **list);

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Wrong Command line argument! try \"./server\"\n");
		return (0);
	}
	sa.sa_sigaction = &sig_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	ft_printf("Server ID: %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

static void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static t_list	*str_list = NULL;
	static char		c;
	static int		i;

	(void)context;
	if (sig == SIGUSR1 || sig == SIGUSR2)
	{
		c = (c << 1) | (sig == SIGUSR2);
		i++;
		if (i == 8)
		{
			append_char(&str_list, c);
			if (c == '\0')
			{
				pfree_list(&str_list);
			}
			c = 0;
			i = 0;
		}
		kill(info->si_pid, SIGUSR1);
	}
}

static void	append_char(t_list **list, char c)
{
	t_list	*new_node;
	t_list	*tmp;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		exit(1);
	new_node->c = c;
	new_node->next = NULL;
	if (*list == NULL)
		*list = new_node;
	else
	{
		tmp = *list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

static void	pfree_list(t_list **list)
{
	t_list	*tmp;
	t_list	*next;

	if (*list == NULL || ((*list)->c == '\0' && (*list)->next == NULL))
		ft_printf("\n");
	else
	{
		tmp = *list;
		while (tmp != NULL)
		{
			ft_printf("%c", tmp->c);
			next = tmp->next;
			free(tmp);
			tmp = next;
		}
		ft_printf("\n");
	}
	*list = NULL;
}
