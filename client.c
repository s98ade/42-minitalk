/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:48:26 by sade              #+#    #+#             */
/*   Updated: 2024/02/22 09:44:26 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    handle_sigusr(int signum)
{
    if (signum == SIGUSR2)
        exit(0);
}

static void send_char(pid_t pid, char *msg)
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

static void send_msg(pid_t pid, char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        send_char(pid, str[i]);
        ++i;
    }
    send_char(pid, 0);
}

int main(int argc, char **argv)
{
    pid_t pid;
    struct sigaction    sa;
    
    sa.sa_handler = &handle_sigusr;
    sigaction(SIGUSR2, &sa, NULL);
    if (argc != 3)
        ft_putstr_fd("Too little arguments!\n", 2);
    else
    {
        pid = ft_atoi(argv[1]);
        if (pid && ft_strlen(argv[2]))
            send_msg(pid, argv[2]);
    }
    return(0);
}