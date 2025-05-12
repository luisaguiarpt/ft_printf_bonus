/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcemon <marcemon@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:33:28 by marcemon          #+#    #+#             */
/*   Updated: 2025/05/10 17:17:03 by marcemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include "../incs/ft_printf.h"

int	ft_putptr(unsigned long nb, char *base, int first)
{
	int	i;

	if (!nb && first)
		return (ft_putstr("(nil)"));
	i = 0;
	if (first)
		i += ft_putstr("0x");
	if (nb > 15)
		i += ft_putptr(nb / 16, base, 0);
	return (i + ft_putchar(base[nb % 16]));
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

int	ft_putnbru(long long nb, int neg, char *base, int ox)
{
	int	count;

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
