/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:34:50 by skhaliff          #+#    #+#             */
/*   Updated: 2022/07/30 14:06:12 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

static int	size_of_n(int n)
{
	int					i;
	unsigned int		num;

	i = 1;
	num = n;
	if (n < 0)
	{
		num = n * (-1);
	}
	while (num / 10)
	{
		num = num / 10;
		i *= 10;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int					count;
	int					len;
	unsigned int		num;

	len = size_of_n(n);
	num = n;
	count = 0;
	if (n < 0)
	{
		ft_putchar('-');
		num = num * (-1);
		count += 1;
	}
	while (len != 0)
	{
		count += ft_putchar((num / len) + '0');
		num = num % len;
		len /= 10;
	}
	return (count);
}
