/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 16:06:24 by mdomnik           #+#    #+#             */
/*   Updated: 2023/09/03 17:42:15 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>

void    errorPrinter(void);

//indexes that store all possible combinations given entry values/ clues
//also stores "guarantees", which represent all commonalities between possiblities 
void fouroneIndex(int a, int b)
{
	char fourone[4] = {1, 2, 3, 4};
}

void threeoneIndex(int a, int b)
{
	char threeone[3][4] = {{2, 1, 3, 4}, {2, 3, 1, 4}, {1, 3, 2, 4}};
	char threeOneGuarantee[2] = {3, 4};// index, digit
}

void threetwoIndex(int a, int b)
{
	char threetwo[3][4] = {{1, 2, 4, 3}, {1, 3, 4, 2}, {2, 3, 4, 1}};
	char threetwoGuarantee[2] = {2, 4};
}

void twooneIndex(int a, int b)
{
	char twoone[2][4] = {{3, 1, 2, 4}, {3, 2, 1, 4}};
	char twoOneGuarantee[2][2] = {{0, 3}, {3, 4}};
}
void twotwoIndex(int a, int b)
{
	char twotwo[6][4] = {{1, 4, 2, 3},{3, 4, 1, 2},{2, 1, 4, 3}
		,{3, 2, 4, 1},{2, 4, 1, 3},{3, 1, 4, 2}};
}
void onefourIndex(int a, int b)
{
	char onefour[4] = {4, 3, 2, 1};
}
void onethreeIndex(int a, int b)
{
	char onethree[3][4] = {{4, 3, 1, 2}, {4, 1, 3, 2}, {4, 2, 3, 1}};
	char oneThreeGuarantee[2] = {0, 4};
}
void twothreeIndex(int a, int b)
{
	char twothree[3][4] = {{3, 4, 2, 1},{2, 4, 3, 1}.{1, 4, 3, 2}};
	char twoThreeGuarantee[2] = {1, 4};
}
void onetwo(int a, int b)
{
	char onetwo[2][4] = {{4, 2, 1, 3}, {4, 1, 2, 3}};
	char oneTwoGuarantee[2][2] = {{0, 4},{3, 3}};
}

void skyscraper(char *values)
{
	char grid[4][4] = {0};
	char pairs[8][2] = {0};
	int i = 0;
	int j = 0;

	while (i <= 8)
	{
		pairs[i][j] = checker2(values[i], values[i + 4])
	}



	while (str[i] != '\0')
	{
		//check for only digits <5 (validate)
		//create a loop that takes all the input from a 
		//string and assigns it accordingly to the pairs array

	}
	//create a loop that takes pair at positions and stores the guarantess in the grid array
	//if first element 

	

}

char  *checker (char *str, char *values)
{
	int	i;
	int	j;
	int	k;
	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (i > 30)
		{
			errorPrinter();
			return(0);
		}
		else if((str[i] >= 49 && str[i] <= 52) || (str[i] == 32))
		{
			if (str[i] >= 49 && str[i] <= 52)
			{
				values[j] = str[i];
				j++;
				k = 0;
			}
			else
			{
				if (k == 1)
				{
					errorPrinter();
					return (0);
				}
				k++;
			}
		}
		else if (((str[i] == 32) && k > 0))
		{
			errorPrinter();
			return (0);
		}
		else
		{
			errorPrinter();
			return (0);
		}
		i++;
	}

	if (j == 16)
	{
		return (values);
	}
	else
	{
		return (0);
	}
}

char	*checker2(char a, char b)
{
	int	i;
	int	j;
	int	k[] = {};
	char	poss[9][2] = {{4,1}, {3,1}, {3,2}, {2,1}, {2,2}, {1,4}, {1,3}, {2,3}, {1,2}};
	char	temp[2] = {a, b};

	i = 0;
	j = 0;
	while (i <= 8)
	{	
		while (temp[0] != poss[j][0] && temp[1] != poss[j][1])
		{
			j++;
		}
		j = 0;
		if (temp[0] == poss[j][0] && temp[1] == poss[j][1])
		{
			k = {('0' + temp[0]), ('0' + temp[1])};
			return (k);
		}
		else
		{
			errorPrinter();
			return (0);
		}
		i++;
	}
	return ();
}

void	errorPrinter(void)
{
	int	i;
        char *error;

	i = 0;
        error = "Error, Invalid Input!\n";

	while (error[i] != '\0')
	{
		write(1, &error[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int main (int argc, char **argv)
{
	char *str;
	char *values;
	int	i;
	int	j;

	i = 0;
	j = 0;
	str = argv[1];
	
	values = malloc(100);
	if (argc == 2)
	{
		checker(str, values);
		skyscraper(values);
			while (values[i] != '\0')
			{
				write(1, &values[i], 1);
				i++;
			}
		
	}
	else
	{
		errorPrinter();
	}
}




