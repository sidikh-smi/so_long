/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:38:49 by skhaliff          #+#    #+#             */
/*   Updated: 2022/07/20 23:43:46 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*copy;

	copy = malloc(size * count);
	if (!copy)
		return (NULL);
	ft_bzero(copy, count * size);
	return (copy);
}
