/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 00:40:45 by skhaliff          #+#    #+#             */
/*   Updated: 2022/07/23 15:07:06 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(char *s)
{
	int	i;

	i =0;
	while (s[i])
	{
		write(1, &s[i++], 1);
	}
	exit(-1);
}