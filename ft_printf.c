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

int check_next(char c)
{
	(void) c;
	return (0);
}

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

int	ft_putnbr_base(long long nb, int neg, char *base, int ox)
{
	int	count;
	char	c;
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
		count += ft_putnbr_base(nb / ft_strlen(base), neg, base, ox);
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

	//write(1, "res:", 4);
	
	i = 0;	
	nbr = nb;
	mag = 0;
	while ((nb/=10))
		++mag;
	++mag;
	while (i < min - max && mag < min)
		i += ft_putchar(' ');
	while (i < (min * (min > max) + max * (max >= min)) - mag)
		i += ft_putchar(pad);
	i += ft_putnbr_base(nbr, (nb < 0), "0123456789", 0);
	return (i);
}

int	ft_printf(char *str, ...)
{
	va_list args;
	int i;
	int count;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '\n')
			count += check_next(str[++i]);
		count += ft_putchar(str[i++]);
	}
	va_end(args);
	return (count);
}
int main (void)
{
	int nb = 42;
//	void *ptr = &nb;
	int res = ft_putnbr_base((long long)nb, (nb < 0), "abcdefghij", 0);
	printf("\n%d\n", res);
	printf("% d\n", nb);
	printf("%13.4d\n", nb);
	ft_nbpad(nb, 13, 4, '0');
}
