/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:08:25 by skhaliff          #+#    #+#             */
/*   Updated: 2022/07/30 16:11:30 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(t_vars *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->map[i])
	{
		j = 0;
		while (d->map[i][j])
		{
			if (d->map[i][j] == '1')
				mlx_put_image_to_window(d->mlx, d->win, d->wall,
					j * 46, i * 46);
			if (d->map[i][j] == 'P')
				mlx_put_image_to_window(d->mlx, d->win, d->player,
					j * 46, i * 46);
			if (d->map[i][j] == 'C')
				mlx_put_image_to_window(d->mlx, d->win, d->col, j * 46, i * 46);
			if (d->map[i][j] == 'E')
				mlx_put_image_to_window(d->mlx, d->win, d->exit,
					j * 46, i * 46);
			j++;
		}
		i++;
	}
	mlx_hook(d->win, 2, 1, key_hook, d);
}
