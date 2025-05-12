/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcemon <marcemon@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:15:34 by marcemon          #+#    #+#             */
/*   Updated: 2025/05/10 17:17:24 by marcemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"
#include "unistd.h"

int	ft_strlen(char *str)
{
	char	*init;

	init = str;
	while (*str)
		str++;
	return (str - init);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	while (*str)
		count += ft_putchar(*str++);
	return (count);
}
