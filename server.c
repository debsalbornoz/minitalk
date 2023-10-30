/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlamark- <dlamark-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 22:31:57 by dlamark-          #+#    #+#             */
/*   Updated: 2023/10/12 13:31:48 by dlamark-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	*add_byte_to_str(unsigned char *str, unsigned char c,
		size_t len)
{
	unsigned char	*temp;
	int				i;

	temp = (unsigned char *)ft_strdup((char *)str);
	free(str);
	if (!temp)
		exit(1);
	str = malloc(sizeof(unsigned char) * (len + 2));
	if (!str)
	{
		free(temp);
		exit(1);
	}
	ft_bzero(str, len + 2);
	i = -1;
	while (temp[++i])
		str[i] = temp[i];
	str[len] = c;
	str[len + 1] = '\0';
	if (temp)
		free(temp);
	return (str);
}

int	add_bits_to_byte(unsigned char received_byte, size_t len, int send_pid)
{
	static unsigned char	*str;

	if (received_byte == '\0' && str)
	{
		if (kill(send_pid, SIGUSR1) == -1)
		{
			free(str);
			exit(1);
		}
		ft_printf("\n%s", str);
		free(str);
		str = NULL;
		return (1);
	}
	if (!str)
	{
		str = malloc(sizeof(unsigned char) * 2);
		if (!str)
			exit(1);
		str[0] = received_byte;
		str[1] = '\0';
	}
	else
		str = add_byte_to_str(str, received_byte, len);
	return (0);
}

void	handler(int signal, siginfo_t *info, void *context)
{
	static unsigned char	bits;
	static int				bit_position;
	static int				pid;
	static size_t			len;

	(void)context;
	if (pid != info->si_pid)
		pid = info->si_pid;
	if (signal == SIGUSR2)
		bits |= (1 << bit_position);
	if (bit_position++ == 7)
	{
		if (add_bits_to_byte(bits, len++, pid) == 1)
			len = 0;
		bits = 0;
		bit_position = 0;
	}
	kill(pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa_signal;
	sigset_t			block_mask;

	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	ft_printf("Server PID: %i\nWaiting for message.... \n", getpid());
	sa_signal.sa_flags = SA_SIGINFO;
	sa_signal.sa_mask = block_mask;
	sa_signal.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa_signal, NULL);
	sigaction(SIGUSR2, &sa_signal, NULL);
	while (1)
		pause();
	return (0);
}
