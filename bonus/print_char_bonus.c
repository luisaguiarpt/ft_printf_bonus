/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcemon <marcemon@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 21:30:02 by marcemon          #+#    #+#             */
/*   Updated: 2025/05/14 11:39:55 by marcemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf_bonus.h"
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	align_char(char c, t_flags flags)
{
	int	i;

	i = 0;
	if (flags.align)
	{
		i += ft_putchar(c);
		while (i < flags.width)
			i += ft_putchar(' ');
	}
	else
	{
		while (i < flags.width - 1)
			i += ft_putchar(' ');
		i += ft_putchar(c);
	}
	return (i);
}

int	print_char(char c, t_flags flags)
{
	if (flags.width > 1)
		return (align_char(c, flags));
	return (ft_putchar(c));
}
