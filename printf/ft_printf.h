/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:20:21 by lufiguei          #+#    #+#             */
/*   Updated: 2024/05/02 18:20:23 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);

int	ft_putstr(char *str);

int	ft_putnbr(int nb);

int	ft_putchar(char c);

int	ft_putptr(unsigned long nb);

int	ft_puthex(unsigned long nb, const char c);

int	ft_unsint(unsigned int n);

int	ft_atoi(const char *nptr);

int	ft_strlen(char *str);

#endif
