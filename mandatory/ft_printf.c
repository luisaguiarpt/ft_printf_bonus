/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcemon <marcemon@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:25:19 by marcemon          #+#    #+#             */
/*   Updated: 2025/05/14 11:39:07 by marcemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int	check_next(char c, va_list args)
{
	va_list	copy;

	va_copy(copy, args);
	if (c == 'd' || c == 'i')
		return (ft_putnbr((long long)va_arg(args, int),
				(va_arg(copy, int) < 0), "0123456789", 0));
	if (c == 'u')
		return (ft_putnbru((long long)va_arg(args, int),
				(va_arg(copy, int) < 0), "0123456789", 0));
	if (c == 'x')
		return (ft_putnbru((long long)va_arg(args, unsigned int),
				(va_arg(copy, unsigned int) < 0), "0123456789abcdef", 0));
	if (c == 'X')
		return (ft_putnbru((long long)va_arg(args, unsigned int),
				(va_arg(copy, unsigned int) < 0), "0123456789ABCDEF", 0));
	if (c == 'p')
		return (ft_putptr(va_arg(args, unsigned long), "0123456789abcdef", 1));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!str)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += check_next(str[++i], args);
			++i;
		}
		else
			count += ft_putchar(str[i++]);
	}
	va_end(args);
	return (count);
}
