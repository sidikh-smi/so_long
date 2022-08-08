/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 21:49:50 by skhaliff          #+#    #+#             */
/*   Updated: 2022/08/02 19:56:23 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	position(t_vars *d)
{
	int	i;
	int	j;

	i = 0;
	d->position.x = 0;
	while (d->map[i])
	{
		j = 0;
		while (d->map[i][j])
		{
			if (d->map[i][j] == 'P')
			{
				d->position.x = j;
				d->position.y = i;
			}
			j++;
		}
		i++;
	}
}
