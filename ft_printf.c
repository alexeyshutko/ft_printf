/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 05:13:49 by gpolyxen          #+#    #+#             */
/*   Updated: 2022/01/09 05:21:55 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		size;
	va_list	vl;

	i = 0;
	size = 0;
	va_start(vl, format);
	while (format[i])
	{
		while_read(&size, vl, format, &i);
		i++;
	}
	va_end(vl);
	return (size);
}

void	while_read(int *size, va_list vl, const char *format, int *i)
{
	if (format[*i] == '%')
	{
		if (format[*i + 1] == 'd' || format[*i + 1] == 'i')
			write_digit(size, vl);
		else if (format[*i + 1] == 'c')
			*size += write_c(va_arg(vl, int));
		else if (format[*i + 1] == 's')
			*size += write_s(va_arg(vl, char *));
		else if (format[*i + 1] == '%')
			*size += write_c('%');
		else if (format[*i + 1] == 'p')
			write_pointer(size, vl);
		else if (format[*i + 1] == 'x')
			write_x_min(size, "0123456789abcdef", vl);
		else if (format[*i + 1] == 'X')
			write_x_min(size, "0123456789ABCDEF", vl);
		else if (format[*i + 1] == 'u')
			write_ui(size, vl);
		(*i)++;
	}
	else
	{
		(*size)++;
		write(1, &format[*i], 1);
	}
}
