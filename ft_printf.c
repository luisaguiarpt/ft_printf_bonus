/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcemon <marcemon@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:25:19 by marcemon          #+#    #+#             */
/*   Updated: 2025/04/26 11:50:25 by marsoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_strlen(char *str)
{
	char	*init;

	init = str;
	while (*str)
		str++;
	return (str - init);
}

int	ft_putnbr(long long nb, int neg, char *base, int ox)
{
	int	count;

	count = (ox) * 2 + neg;
	if (neg)
	{
		nb *= -1;
		write(1, "-", 1);
		neg = 0;
	}
	if (ox)
	{
		write(1, "0x", 2);
		ox = 0;
	}
	if (nb > ft_strlen(base) - 1)
		count += ft_putnbr(nb / ft_strlen(base), neg, base, ox);
	return (count += ft_putchar(base[nb % ft_strlen(base)]));
}

int ft_putnbru(long long nb, int neg, char *base, int ox)
{
	int count;

	count = (ox) * 2;
	if (neg)
	{
		nb = UINT_MAX + nb + 1;
		neg = 0;
	}
	if (ox)
	{
		write(1, "0x", 2);
		ox = 0;
	}
	if (nb > ft_strlen(base) - 1)
		count += ft_putnbr(nb / ft_strlen(base), neg, base, ox);
	return (count += ft_putchar(base[nb % ft_strlen(base)]));
}

int ft_putstr(char *str)
{
	char	*init;

	init = str;
	while (*str)
		write(1, str++, 1);
	return (str - init);
}

int	ft_nbpad(int nb, int min, int max, char pad)
{
	int i;
	int mag;
	int nbr;

	i = 0;	
	nbr = nb;
	mag = 0;
	while (nb)
	{
		++mag;
		nb /= 10;
	}
	++mag;
	while (i < min - max && mag < min)
		i += ft_putchar(' ');
	while (i < (min * (min > max) + max * (max >= min)) - mag)
		i += ft_putchar(pad);
	i += ft_putnbr(nbr, (nb < 0), "0123456789", 0);
	return (i);
}

int check_next(char c, va_list args)
{
	(void) c;
	va_list copy;

	va_copy(copy, args);
	if (c == 'd' || c == 'i')
		return (ft_putnbr((long long)va_arg(args, int), 
					(va_arg(copy, int) < 0), "0123456789", 0));
	if (c == 'u')
		return (ft_putnbru((long long)va_arg(args, int), 
					(va_arg(copy, int) < 0), "0123456789", 0));
	if (c == 'x')
		return (ft_putnbru((long long)va_arg(args, unsigned int),
					(va_arg(copy, int) < 0), "0123456789abcdef", 0));
	if (c == 'X')
		return (ft_putnbru((long long)va_arg(args, unsigned int),
					(va_arg(copy, int) < 0), "0123456789ABCDEF", 0));
	if (c == 'p')
	{
		if (!va_arg(copy, unsigned long))
			return (ft_putstr("(null)"));
		return (ft_putnbr((long long) va_arg(args, unsigned long),
					(va_arg(copy, int) < 0), "0123456789abcdef", 1));
	}
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int i;
	int count;

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

// int main (void)
// {
// 	int	res = printf("%u\n", -9);
// 	int	res2 = ft_printf("%u\n", -9);
//	printf("%i\n", res);
//	printf("%i\n", res2);
// }
