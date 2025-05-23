/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcemon <marcemon@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:32:28 by marcemon          #+#    #+#             */
/*   Updated: 2025/05/14 11:42:55 by marcemon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_putchar(char c);
int	ft_printf(const char *str, ...);
int	ft_putptr(unsigned long ptr, char *base, int first);
int	ft_putstr(const char *str);
int	ft_strlen(char *str);
int	ft_putnbr(long long nb, int neg, char *base, int ox);
int	ft_putnbru(long long nb, int neg, char *base, int ox);
int	ft_nbpad(int nb, int min, int max, char pad);
int	check_next(char c, va_list args);

#endif
