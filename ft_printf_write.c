/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 05:17:20 by gpolyxen          #+#    #+#             */
/*   Updated: 2022/01/09 05:20:57 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_digit(int *size, va_list vl)
{
	int		num;

	num = va_arg(vl, int);
	write_i(num);
	*size += get_size_i(num, 10);
}

void	write_pointer(int *size, va_list vl)
{
	unsigned long	num;

	num = va_arg(vl, unsigned long);
	write(1, "0x", 2);
	write_p(num, "0123456789abcdef");
	*size += get_size_p(num, 16);
}

void	write_x_min(int *size, const char *set, va_list vl)
{
	unsigned int	num;

	num = va_arg(vl, unsigned int);
	write_x_low(num, set);
	*size += get_size_u(num, 16);
}

void	write_ui(int *size, va_list vl)
{
	unsigned int	num;

	num = va_arg(vl, unsigned int);
	write_u(num);
	*size += get_size_u(num, 10);
}
