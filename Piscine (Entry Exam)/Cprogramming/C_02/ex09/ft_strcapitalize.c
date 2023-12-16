/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:20:58 by mdomnik           #+#    #+#             */
/*   Updated: 2023/08/30 15:43:59 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcapitalize(char *str);
int		checker(char *str);

char	*ft_strcapitalize(char *str)
{
	char	*current;
	char	*previous;

	current = str;
	while (*current != '\0')
	{
		previous = current - 1;
		if (checker(current) == 1 || (checker(current) == 2))
		{
			if (checker(previous) == 3)
			{
				if (checker(current) == 1)
					*current = *current - 32;
			}
			else
			{
				if (checker(current) == 2)
					*current = *current + 32;
			}
		}
		current++;
	}
	return (str);
}

int	checker(char *str)
{
	if (*str >= '0' && *str <= '9')
	{
		return (0);
	}
	else if (*str >= 'a' && *str <= 'z')
	{
		return (1);
	}
	else if (*str >= 'A' && *str <= 'Z')
	{
		return (2);
	}
	else
	{
		return (3);
	}
}

/*
int	main (void)
{
	char	*x;
	char	test[100] = "s123alut, coMMEnt !tu vAs ?";
	

	x = ft_strcapitalize(test);

	printf("%s", x);
}
*/
