/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 22:32:03 by dlamark-          #+#    #+#             */
/*   Updated: 2023/10/12 15:12:08 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*g_temp;

int	send_bit(int bit, int pid)
{
	static int	bit_position;

	if (bit_position == 8)
		bit_position = 0;
	if (bit & (1 << bit_position++))
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_printf("Error\n");
			free(g_temp);
			exit(1);
		}
	}
	else
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_printf("Error\n");
			free(g_temp);
			exit(1);
		}
	}
	return (bit_position);
}

void	send_message(int pid, char *msg)
{
	static int		stored_pid;
	static size_t	i;
	static size_t	len;
	size_t			index_bit;

	index_bit = 0;
	if (stored_pid == 0)
		stored_pid = pid;
	if (!g_temp)
		g_temp = ft_strdup(msg);
	if (len == 0)
		len = ft_strlen(g_temp);
	if (i < len)
		index_bit = send_bit(g_temp[i], stored_pid);
	else if (i == len)
		index_bit = send_bit('\0', stored_pid);
	if (index_bit == 8)
		i++;
	if (index_bit == 8 && g_temp && i == len)
		free(g_temp);
	return ;
}

void	handler(int signal, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signal == SIGUSR1)
	{
		ft_printf("Success!\n");
		exit(0);
	}
	else if (signal == SIGUSR2)
	{
		send_message(0, NULL);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa_signal;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	sa_signal.sa_flags = 0;
	sa_signal.sa_mask = block_mask;
	sa_signal.sa_sigaction = handler;
	if (argc == 3 && argv[2][0] != '\0')
	{
		sigaction(SIGUSR1, &sa_signal, NULL);
		sigaction(SIGUSR2, &sa_signal, NULL);
		send_message(ft_atoi(argv[1]), argv[2]);
		while (1)
			sleep(1);
		return (1);
	}
	else
	{
		ft_printf("Error: incorrect number of arguments.\n");
		return (1);
	}
}
