/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:47:00 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/24 20:29:38 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/ft_printf/ft_printf.h"
#include "libraries/Libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void	signal_handler(int signal)
{
	static unsigned char	letter;
	static int				iter = 0;

	if (signal == SIGUSR1)
		letter |= (0 << iter);
	else
		letter |= (1 << iter);
	iter++;
	if (iter == 8)
	{
		ft_putchar_fd(letter, 1);
		iter = 0;
		letter = 0;
	}
}

void	config_sygnals(void)
{
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
}

int	main(void)
{
	ft_printf("Server PID [%d]\n", getpid());
	while (1)
		config_sygnals();
	return (0);
}
