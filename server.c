/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:48:38 by sade              #+#    #+#             */
/*   Updated: 2024/02/21 10:11:24 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    handle_error(char *error_msg)
{
    ft_putstr_fd(error_msg, 2);
    ft_putchar_fd('\n', 2);
    exit(1);
}

static void handle_sigusr(int signum, siginfo_t *info, void *context)
{
    static int bit_itr = 8;
    static unsigned char c;
    
    (void)context;
    if (signum == SIGUSR1)
        c |= (1 << bit_itr);
    --bit_itr;
    if (bit_itr < 0 && c)
    {
        ft_putchar_fd(c, STDOUT_FILENO);
        c = 0;
        bit_itr = 8;
        if(kill(info->si_pid, SIGUSR2) == -1)
            handle_error("SIGUSR2 Error");
    }
    if(kill(info->si_pid, SIGUSR1) == -1)
        handle_error("SIGUSR1 Error");
}

void    config_signals(void)
{
    struct sigaction    sa;
    
    sa.sa_sigaction = &handle_sigusr;
    sa.sa_flags = SA_SIGINFO;
    if(sigaction(SIGUSR1, &sa, NULL) == -1)
        handle_error("SIGUSR1 Error");
    if(sigaction(SIGUSR2, &sa, NULL) == -1)
        handle_error("SIGUSR2 Error");
}

int main(void)
{
    pid_t pid;

    pid = getpid();
    printf("Server successfully started.\n");
    printf("The server PID is: %d\n", pid);
    config_signals();
    while (1)
        pause();
}