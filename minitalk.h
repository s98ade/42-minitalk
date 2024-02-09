/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:48:49 by sade              #+#    #+#             */
/*   Updated: 2024/02/09 11:19:03 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
#define CLIENT_H

#include "../Libft/libft.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void    handle_error(char *error_msg);

#endif