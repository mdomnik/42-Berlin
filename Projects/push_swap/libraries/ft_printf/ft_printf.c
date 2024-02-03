/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdomnik <mdomnik@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:32:57 by mdomnik           #+#    #+#             */
/*   Updated: 2024/02/03 18:25:07 by mdomnik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_input(char specifier, va_list args);
static int	ft_printaddress(va_list args);
static int	ft_printaddressdigit(unsigned long long int n);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			count += print_input(*(++format), args);
		}
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(args);
	return (count);
}

static int	print_input(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_printchar(va_arg(args, int));
	else if (specifier == 's')
		count += ft_printstr(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_printdigit((long)(va_arg(args, int)), 10, 0);
	else if (specifier == 'x')
		count += ft_printdigit((long)(va_arg(args, unsigned int)), 16, 0);
	else if (specifier == 'u')
		count += ft_printdigit((long)(va_arg(args, unsigned int)), 10, 0);
	else if (specifier == 'X')
		count += ft_printdigit((long)(va_arg(args, unsigned int)), 16, 1);
	else if (specifier == 'p')
	{
		count += ft_printaddress(args);
	}
	else
		count += write(1, &specifier, 1);
	return (count);
}

static int	ft_printaddress(va_list args)
{
	int						count;
	unsigned long long int	num;

	count = 0;
	num = va_arg(args, unsigned long long int);
	if (num == 0)
		count += ft_printstr("(nil)");
	else
	{
		count += write(1, "0x", 2);
		count += ft_printaddressdigit(num);
	}
	return (count);
}

static int	ft_printaddressdigit(unsigned long long int n)
{
	int						count;
	char					*symbols;

	symbols = "0123456789abcdef";
	if (n < 16)
	{
		return (ft_printchar(symbols[n]));
	}
	else
	{
		count = ft_printaddressdigit((n / 16));
		return (count + ft_printaddressdigit(n % 16));
	}
}
