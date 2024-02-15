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

// Function to add a byte to a string
unsigned char *add_byte_to_str(unsigned char *str, unsigned char c, size_t len)
{
    unsigned char *temp;
    int i;

    // Duplicate the existing string
    temp = (unsigned char *)ft_strdup((char *)str);
    free(str);
    if (!temp)
        exit(1);

    // Allocate memory for the new string
    str = malloc(sizeof(unsigned char) * (len + 2));
    if (!str)
    {
        free(temp);
        exit(1);
    }
    ft_bzero(str, len + 2);
    // Copy the content from the duplicated string to the new string
    i = -1;
    while (temp[++i])
        str[i] = temp[i];
    // Add the new byte to the string
    str[len] = c;
    str[len + 1] = '\0';
    if (temp)
        free(temp);

    return str;
}

// Function to add received bits to a byte and handle message completion
int add_bits_to_byte(unsigned char received_byte, size_t len, int send_pid)
{
    static unsigned char *str;

    if (received_byte == '\0' && str)
    {
        // Send SIGUSR1 to acknowledge the end of the message
        if (kill(send_pid, SIGUSR1) == -1)
        {
            free(str);
            exit(1);
        }
        // Print the received message and free the string
        ft_printf("\n%s", str);
        free(str);
        str = NULL;
        return 1;
    }
    // Allocate memory for the initial byte if the string is empty
    if (!str)
    {
        str = malloc(sizeof(unsigned char) * 2);
        if (!str)
            exit(1);

        // Initialize the string with the received byte
        str[0] = received_byte;
        str[1] = '\0';
    }
    else
    {
        // Add the received byte to the string
        str = add_byte_to_str(str, received_byte, len);
    }

    return 0;
}

// Signal handler function
void handler(int signal, siginfo_t *info, void *context)
{
    static unsigned char bits;
    static int bit_position;
    static int pid;
    static size_t len;

    (void)context;

    // Update the process ID if it changes
    if (pid != info->si_pid)
        pid = info->si_pid;

    // Process received bits when SIGUSR2 is received
    if (signal == SIGUSR2)
        bits |= (1 << bit_position);

    // Check if a full byte has been received
    if (bit_position++ == 7)
    {
        // Add the received bits to the byte and handle message completion
        if (add_bits_to_byte(bits, len++, pid) == 1)
            len = 0;

        // Reset variables for the next byte
        bits = 0;
        bit_position = 0;
    }

    // Send a SIGUSR2 to acknowledge the received bit
    kill(pid, SIGUSR2);
}

int main(void)
{
    struct sigaction sa_signal;
    sigset_t block_mask;

    // Initialize the block_mask
    sigemptyset(&block_mask);
    sigaddset(&block_mask, SIGINT);
    sigaddset(&block_mask, SIGQUIT);

    ft_printf("Server PID: %i\nWaiting for message.... \n", getpid());

    // Configure signal handler for SIGUSR1 and SIGUSR2
    sa_signal.sa_flags = SA_SIGINFO;
    sa_signal.sa_mask = block_mask;
    sa_signal.sa_sigaction = handler;
    sigaction(SIGUSR1, &sa_signal, NULL);
    sigaction(SIGUSR2, &sa_signal, NULL);

    // Infinite loop to wait for signals
    while (1)
        pause();

    return 0;
}
