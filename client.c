/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:48:26 by sade              #+#    #+#             */
/*   Updated: 2024/02/08 21:23:35 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void    handler_sigusr(int signum)
{
    if(signum == SIGUSR2)
    {
        ft_putstr_fd("Sending completed.\n", 1);
        exit(0);
    }
}

static void send_msg(pid_t pid, char *msg)
{
    unsigned char c;
    int bits;

    while (*msg)
    {
        c = *msg;
        bits = 8;
        while (--bits)
        {
            if (c & 0b10000000)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            usleep(50);
            c <<= 1;
        }
        ++msg;
    }
}

int main(int argc, char **argv)
{
    pid_t pid;

    if (argc != 3)
        ft_putstr_fd("Too little arguments!\n", 2);
    else
    {
        pid = ft_atoi(argv[1]);
        while (argv[2])
            send_msg(pid, ++argv[2]);
    }
}