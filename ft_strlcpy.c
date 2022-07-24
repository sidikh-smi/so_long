/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:03:20 by skhaliff          #+#    #+#             */
/*   Updated: 2022/07/23 11:35:32 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	res;
	size_t	i;

	res = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while (i < (dstsize - 1) && i < res && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (res);
}
