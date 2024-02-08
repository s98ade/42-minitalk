/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:48:38 by sade              #+#    #+#             */
/*   Updated: 2024/02/08 21:47:41 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void handle_sigusr(int signum, siginfo_t *info, void *context)
{
    static int bit_itr;
    static unsigned char c;
    
    bit_itr = 0;
    (void)context;
    if (bit_itr == 0)
        bit_itr = 8;
    if (signum == SIGUSR1)
        c |= (1 << bit_itr);
    --bit_itr;
    if (bit_itr == 0 && c)
    {
        ft_putchar_fd(c, 1);
        c = 0;
    }
}

int main(int argc, char **argv)
{
    struct sigaction sa;
    pid_t pid;

    pid = getpid();
    ft_printf("The server PID is: %d\n", pid);
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = &handle_sigusr;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();
    return (0);
}