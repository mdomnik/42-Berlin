/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 14:35:31 by mdomnik           #+#    #+#             */
/*   Updated: 2023/09/02 15:15:26 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void skyChecker_horiz(int a, int b);
void printer(int a, int b, int c, int d);
void index(int a);

int main (void)
{
	int	a;
	int	b;

	a = 4;
	b = 1;
	skyChecker_Horiz(a, b);
}

void skyChecker_Horiz(int a, int b)
{
	
}

void printer(int a, int b, int c, int d)
{
	write(1, &a, 1);
	write(1, " ", 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, " ", 1);
	write(1, &d, 1);
	write(1, "\n", 1);
}

void index(int a)
{
	char fourone[];
	char threeone[];
	char threetwo[];
	char twoone[];
	char twotwo[];

	fourone[] = {1, 2, 3, 4
}
