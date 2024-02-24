/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:46:54 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/24 20:05:36 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/ft_printf/ft_printf.h"
#include "libraries/Libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void	send_message(int pid, char *message)
{
	int	i;
	int	letter;
	int	bit_count;
	int	bit;
	
	i = 0;
	while(message[i] != '\0')
	{
		letter = message[i];
		bit_count = 0;
		while (bit_count <= 7)
		{	
			bit = (letter >> bit_count) & 1; 
			if(bit == 0)
			{
				kill(pid, SIGUSR1);
			}
			else
			{
				kill(pid, SIGUSR2);
			}
			usleep(100);
			bit_count++;
		}
		i++;
	}
}

int main (int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
		ft_printf("wrong amount of parameters | input PID and the message you want to send\n");
	else
	{
		pid = ft_atoi(argv[1]);
		send_message(pid, argv[2]);
	}
}