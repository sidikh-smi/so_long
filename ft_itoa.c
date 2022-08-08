/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:03:26 by skhaliff          #+#    #+#             */
/*   Updated: 2022/08/03 11:21:49 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	size_of_n(int n)
{
	int		i;
	long	num;

	i = 1;
	num = n;
	if (n < 0)
	{
		num = n * (-1);
		i = i + 1;
	}
	while (num / 10)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

void	filling_str(char *s, int len, long num, int i)
{
	while (len != i)
	{
		s[len - 1] = (num % 10) + '0';
		num = num / 10;
		len --;
	}
}

char	*ft_itoa(int n)
{
	int				len;
	char			*s;
	int				last;
	int				i;
	long			num;

	i = 0;
	len = (int)size_of_n(n);
	last = len - 1;
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	num = n;
	if (n < 0)
	{
		s[i] = '-';
		num = num * (-1);
		i = i + 1;
	}
	filling_str(s, len, num, i);
	s[last + 1] = '\0';
	return (s);
}
