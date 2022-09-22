/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolyxen <gpolyxen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 04:23:59 by gpolyxen          #+#    #+#             */
/*   Updated: 2022/01/09 05:15:16 by gpolyxen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_c(char a)
{
	write(1, &a, 1);
	return (1);
}

int	write_s(char *a)
{
	int	i;

	if (a == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (a[i])
	{
		write (1, &a[i], 1);
		i++;
	}
	return (i);
}

void	write_i(int i)
{
	char	a;
	int		size;

	size = 0;
	if (i == -2147483648)
		write(1, "-2147483648", 11);
	else if (i > 9)
	{
		write_i(i / 10);
		a = i % 10 + '0';
		write(1, &a, 1);
	}
	else if (i < 0)
	{
		write(1, "-", 1);
		write_i(-i);
	}
	else
	{
		a = i + '0';
		write(1, &a, 1);
	}
}

int	get_size_i(int num, int j)
{
	int	count;

	count = 0;
	if (num == 0)
	{
		return (1);
	}
	if (num < 0)
	{
		count++;
	}
	while (num != 0)
	{
		num = num / j;
		count++;
	}
	return (count);
}

void	write_u(unsigned int i)
{
	char	a;

	if (i > 9)
	{
		write_i(i / 10);
		a = i % 10 + '0';
		write(1, &a, 1);
	}
	else
	{
		a = i + '0';
		write(1, &a, 1);
	}
}
