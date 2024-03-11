/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:48:38 by sade              #+#    #+#             */
/*   Updated: 2024/03/11 10:18:38 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static  t_info  global_info;

void    handle_error(char *error_msg)
{
    ft_putstr_fd(error_msg, 2);
    ft_putchar_fd('\n', 2);
    exit(1);
}

int    reset(int received)
{
    if (!received)
        kill(global_info.pid, SIGUSR2);
    global_info.pid = 0;
    if (global_info.str)
    {
        free(global_info.str);
        global_info.str = NULL;
    }
    global_info.tmp_char = 0;
    global_info.bit = 0;
    return(0);
}

int str_saver(void)
{
    char *tmp;

    if (!global_info.tmp_char)
        return(1);
    if (!global_info.str)
    {
        global_info.str = malloc(sizeof(char) * 2);
        if (!global_info.str)
            return(reset(0));
        global_info.str[0] = global_info.tmp_char;
        global_info.str[1] = '\0';
    }
    else
    {
        tmp = global_info.str;
        global_info.str = ft_strjoin(global_info.str, &global_info.tmp_char);
        free(tmp);
        tmp = NULL;
        if (!global_info.str)
            return(reset(0));
    }
    return(1);
}

static void handle_sigusr(int signum, siginfo_t *s_info, void *context)
{
    (void)context;
    if (!global_info.pid)
        global_info.pid = s_info->si_pid;
    if (!global_info.bit)
    {
        if(!str_saver())
            return ;
        global_info.tmp_char = 0;
        global_info.bit = 0b10000000;
    }
    if (signum == SIGUSR1)
        global_info.tmp_char += global_info.bit;
    global_info.bit >>= 1;
    if (!global_info.bit && !global_info.tmp_char)
    {
        ft_printf("%s\n", global_info.str);
        reset(1);
    }
}

int main(void)
{
    struct sigaction    sa;
    pid_t pid;

    pid = getpid();
    ft_printf("Server successfully started.\n");
    ft_printf("The server PID is: %d\n", pid);
    sa.sa_sigaction = &handle_sigusr;
    sa.sa_flags = SA_SIGINFO;
    if(sigaction(SIGUSR1, &sa, NULL) == -1)
        handle_error("SIGUSR1 Error");
    if(sigaction(SIGUSR2, &sa, NULL) == -1)
        handle_error("SIGUSR2 Error");
    while (1)
        pause();
}