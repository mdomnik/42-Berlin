/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:42:40 by mdomnik           #+#    #+#             */
/*   Updated: 2023/09/10 21:46:49 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
void    ft_putstr(char *str)
{
        while(*str)
        {
                write(1, str, 1);
                str++;
        }
}
char    *read_open(char *ro)
{
        int     i;
        char    c;
	int	j;
	char *copy;
	int	k;

        i = open(ro, O_RDONLY);
        if (i < 0)
        {
                ft_putstr("Error\n");
                return (0);
        }
        while (read(i, &c, 1) > 0)
        {
//                ft_putstr(&c);
        }
	copy = malloc(j);
	copy = ro;
	while (*copy != '\0')
	{
		k++;
	}
	write(1, &k, 1);
        close(i);
        return(0);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*str2;
	int		i;

	str2 = str;
	if (*to_find == '\0')
		return (str);
	while (*str2)
	{
		i = 0;
		if (*str2 == to_find[0])
		{
			while ((str2[i] == to_find[i]) && (to_find[i] != '\0'))
			{
				i++;
			}
			if (to_find[i] == '\0')
			{
				return (str2);
			}
		}
		str2++;
	}
	return (0);
}

int	strlength(char *nb)
{
	int	i;

	i = 0;
	while (nb[i] != '\0')
	{
		i++;
	}
	return(i);
}

void	find(char *nb)
{
	int	i;
	int	j;

	i = strlength(nb);
	j = 0;
	while (nb[j] != '\0')
	{
		write(1, &nb[j], 1);
		while (i - 1 > 0)
		{
			write(1, "0", 1);
			i--;
		}
		write(1, "\n", 1);
		j++;
	}
	

//	read_open("numbers.dict");
}

int     main(int argc, char **argv)
{
	if (argc == 2)
		find(argv[1]);
}
