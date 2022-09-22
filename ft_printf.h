/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 03:32:29 by gpolyxen          #+#    #+#             */
/*   Updated: 2022/01/09 05:16:39 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "ft_printf.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		write_c(char a);
int		write_s(char *a);
void	write_i(int i);
int		get_size_i(int num, int j);
void	write_u(unsigned int i);
int		get_size_u(unsigned int num, int j);
int		write_p(unsigned long i, const char *str);
int		get_size_p(unsigned long i, int j);
int		write_x_low(unsigned int i, const char *str);
int		get_size_x_low(unsigned int num, int j);
void	write_digit(int *size, va_list vl);
void	write_pointer(int *size, va_list vl);
void	write_x_min(int *size, const char *set, va_list vl);
void	write_ui(int *size, va_list vl);
void	while_read(int *size, va_list vl, const char *format, int *i);

#endif
