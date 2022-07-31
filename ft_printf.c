/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:53:44 by skhaliff          #+#    #+#             */
/*   Updated: 2022/07/31 11:13:35 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	put_print(va_list arg, const char s)
{
	int	len_frm;

	len_frm = 0;
	if (s == 'd')
		len_frm += ft_putnbr(va_arg(arg, int));
	return (len_frm);
}

int	ft_printf(char *format, ...)
{
	int		len_frm;
	va_list	arg;
	int		i;

	i = 0;
	len_frm = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len_frm = len_frm + put_print(arg, format[i + 1]);
			i++;
		}
		else
			len_frm += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (len_frm);
}
