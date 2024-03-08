/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrauer <kbrauer@student.42vienna.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:55:51 by kbrauer           #+#    #+#             */
/*   Updated: 2023/12/21 14:10:23 by kbrauer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include "../lib/printf/ft_printf.h"
# include "../lib/libft_bonus/libft.h"

# define ERROR1 "Wrong number of arguments\n"
# define ERROR2 "Incorrect server PID\n"
# define ERROR3 "Sending signal failed\n"
# define ERROR4 "Signal handling failed\n"
# define ERROR5 "Signal interupted, connection lost\n"

void	ex_error(char *str);

#endif