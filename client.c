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

static char *g_temp;

// Function to send a single bit using signals
int send_bit(int bit, int pid)
{
    static int bit_position;

    // Reset bit_position after 8 bits
    if (bit_position == 8)
        bit_position = 0;

    // Send SIGUSR2 if the bit is 1, SIGUSR1 if the bit is 0
    if (bit & (1 << bit_position++))
    {
        if (kill(pid, SIGUSR2) == -1)
        {
            perror("Error");
            free(g_temp);
            exit(1);
        }
    }
    else
    {
        if (kill(pid, SIGUSR1) == -1)
        {
            perror("Error");
            free(g_temp);
            exit(1);
        }
    }
    return bit_position;
}

// Function to send a message using signals
void send_message(int pid, char *msg)
{
    static int stored_pid;
    static size_t i;
    static size_t len;
    size_t index_bit;

    index_bit = 0;

    // Store pid on first call
    if (stored_pid == 0)
        stored_pid = pid;
    if (!g_temp)
        g_temp = strdup(msg);
    if (len == 0)
        len = strlen(g_temp);

    // Send each bit of the message
    if (i < len)
        index_bit = send_bit(g_temp[i], stored_pid);
    else if (i == len)
        index_bit = send_bit('\0', stored_pid);

    // Increment index after sending 8 bits
    if (index_bit == 8)
        i++;

    // Free the message when all bits are sent
    if (index_bit == 8 && g_temp && i == len)
        free(g_temp);

    return;
}

// Signal handler function
void handler(int signal, siginfo_t *info, void *context)
{
    (void)info;
    (void)context;
    if (signal == SIGUSR1)
    {
        printf("Success!\n");
        exit(0);
    }
    else if (signal == SIGUSR2)
    {
        send_message(0, NULL);
    }
}

int main(int argc, char **argv)
{
    struct sigaction sa_signal;
    sigset_t block_mask;

    // Initialize block_mask
    sigemptyset(&block_mask);

    // Configure signal handler
    sa_signal.sa_flags = 0;
    sa_signal.sa_mask = block_mask;
    sa_signal.sa_sigaction = handler;

    if (argc == 3 && argv[2][0] != '\0')
    {
        // Register signal handlers for SIGUSR1 and SIGUSR2
        sigaction(SIGUSR1, &sa_signal, NULL);
        sigaction(SIGUSR2, &sa_signal, NULL);

        // Send the message
        send_message(atoi(argv[1]), argv[2]);

        // Infinite loop to keep the process running
        while (1)
            sleep(1);

        return 1;
    }
    else
    {
        printf("Error: incorrect number of arguments.\n");
        return 1;
    }
}