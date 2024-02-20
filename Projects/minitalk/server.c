/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:47:00 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/20 17:18:59 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/ft_printf/ft_printf.h"
#include "libraries/Libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int	binarytodecimal(char *binary_char)
{
	int	decimal;

	while (*binary_char != '\0')
	{
		decimal = decimal * 2 + (*binary_char - 0);
		binary_char++;
	}
	
	return (decimal);
}

void signal_handler(int	signal)
{
	static char		binary_char[9];
	static	int		i;
	int				decimal;

	if (!i)
		i = 0;
	if (signal == SIGUSR1)
		binary_char[i] = '0';
	else
		binary_char[i] = '1';
	i++;
	if (i == 8)
	{
		binary_char[8] = '\0';
		decimal = binarytodecimal(binary_char);
		ft_printf("%c", (char)decimal);
	}
}

int main (void)
{
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	ft_printf("Server PID [%d] | establish connection using ./client <PID> <message>\n", getpid());
	while (1)
		sleep(1);
	return (0);
}
