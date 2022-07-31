/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:51:52 by skhaliff          #+#    #+#             */
/*   Updated: 2022/07/31 12:31:10 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_size(t_vars *d)
{
	int	i;

	i = 0;
	d->map_width = ft_strlen(d->map[0]) * 46;
	while (d->map[i])
		i++;
	d->map_height = i * 46;
}

int	close_win(t_vars *d)
{
	exit(0);
	return (0);
}

void	conter_col(t_vars *d)
{
	int	i;
	int	j;

	i = 0;
	d->collectibles = 0;
	while (d->map[i])
	{
		j = 0;
		while (d->map[i][j])
		{
			if (d->map[i][j] == 'C')
				d->collectibles++;
			j++;
		}
		i++;
	}
}

void	init_image(t_vars *d)
{
	d->col = mlx_xpm_file_to_image(d->mlx, "images/col.xpm",
			&d->map_width, &d->map_height);
	d->exit = mlx_xpm_file_to_image(d->mlx, "images/exit.xpm",
			&d->map_width, &d->map_height);
	d->player = mlx_xpm_file_to_image(d->mlx, "images/p.xpm",
			&d->map_width, &d->map_height);
	d->wall = mlx_xpm_file_to_image(d->mlx, "images/wall.xpm",
			&d->map_width, &d->map_height);
	d->bg = mlx_xpm_file_to_image(d->mlx, "images/bg.xpm",
			&d->map_width, &d->map_height);
}

void	init_map(t_vars *d)
{
	d->pas = 0;
	init_size(d);
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, d->map_width, d->map_height, "so_long");
	init_image(d);
	conter_col(d);
	mlx_hook(d->win, 17, 1, close_win, d);
	position(d);
}
