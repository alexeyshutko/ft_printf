/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 05:13:41 by gpolyxen          #+#    #+#             */
/*   Updated: 2022/01/09 05:13:57 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_size_u(unsigned int num, int j)
{
	int	count;

	count = 0;
	if (num == 0)
	{
		return (1);
	}
	while (num != 0)
	{
		num = num / j;
		count++;
	}
	return (count);
}

int	write_p(unsigned long i, const char *str)
{
	if (i > 15)
	{
		write_p(i / 16, str);
		write(1, &str[i % 16], 1);
	}
	else
	{
		write(1, &str[i], 1);
	}
	return (0);
}

int	get_size_p(unsigned long num, int j)
{
	int	count;

	if (num == 0)
		return (3);
	count = 0;
	while (num != 0)
	{
		num = num / j;
		count++;
	}
	return (count + 2);
}

int	write_x_low(unsigned int i, const char *str)
{
	if (i > 15)
	{
		write_x_low(i / 16, str);
		write(1, &str[i % 16], 1);
	}
	else
	{
		write(1, &str[i], 1);
	}
	return (0);
}

int	get_size_x_low(unsigned int num, int j)
{
	int	count;

	count = 0;
	if (num == 0)
	{
		return (1);
	}
	while (num != 0)
	{
		num = num / j;
		count++;
	}
	return (count);
}
