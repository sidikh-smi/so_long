/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:18:04 by skhaliff          #+#    #+#             */
/*   Updated: 2022/07/31 14:25:34 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_d(t_vars *d)
{
	if (d->map[d->position.y][d->position.x + 1] != '1'
		&& d->map[d->position.y][d->position.x + 1] != 'E')
	{
		d->pas++;
		counter(d);
		mlx_put_image_to_window(d->mlx, d->win, d->player,
			(d->position.x + 1) * 46, d->position.y * 46);
		mlx_put_image_to_window(d->mlx, d->win, d->bg,
			d->position.x * 46, d->position.y * 46);
		if (d->map[d->position.y][d->position.x + 1] == 'C')
			d->collectibles--;
		d->map[d->position.y][d->position.x + 1] = 'P';
		d->map[d->position.y][d->position.x] = '0';
		position(d);
	}
	else if (d->map[d->position.y][d->position.x + 1] == 'E'
		&& d->collectibles == 0)
	{
		exit(0);
	}
}

void	draw_a(t_vars *d)
{
	if (d->map[d->position.y][d->position.x - 1] != '1'
		&& d->map[d->position.y][d->position.x - 1] != 'E')
	{
		d->pas++;
		counter(d);
		mlx_put_image_to_window(d->mlx, d->win, d->player,
			(d->position.x - 1) * 46, d->position.y * 46);
		mlx_put_image_to_window(d->mlx, d->win, d->bg,
			d->position.x * 46, d->position.y * 46);
		if (d->map[d->position.y][d->position.x - 1] == 'C')
			d->collectibles--;
		d->map[d->position.y][d->position.x - 1] = 'P';
		d->map[d->position.y][d->position.x] = '0';
		position(d);
	}
	else if (d->map[d->position.y][d->position.x - 1] == 'E'
		&& d->collectibles == 0)
	{
		exit(0);
	}
}

void	draw_s(t_vars *d)
{
	if (d->map[d->position.y + 1][d->position.x] != '1'
		&& d->map[d->position.y + 1][d->position.x] != 'E')
	{
		d->pas++;
		counter(d);
		mlx_put_image_to_window(d->mlx, d->win, d->player,
			d->position.x * 46, (d->position.y + 1) * 46);
		mlx_put_image_to_window(d->mlx, d->win, d->bg,
			d->position.x * 46, d->position.y * 46);
		if (d->map[d->position.y + 1][d->position.x] == 'C')
			d->collectibles--;
		d->map[d->position.y + 1][d->position.x] = 'P';
		d->map[d->position.y][d->position.x] = '0';
		position(d);
	}
	else if (d->map[d->position.y + 1][d->position.x] == 'E'
		&& d->collectibles == 0)
	{
		exit(0);
	}
}

void	draw_w(t_vars *d)
{
	if (d->map[d->position.y - 1][d->position.x] != '1'
		&& d->map[d->position.y - 1][d->position.x] != 'E')
	{
		d->pas++;
		counter(d);
		mlx_put_image_to_window(d->mlx, d->win, d->player,
			d->position.x * 46, (d->position.y - 1) * 46);
		mlx_put_image_to_window(d->mlx, d->win, d->bg,
			d->position.x * 46, d->position.y * 46);
		if (d->map[d->position.y - 1][d->position.x] == 'C')
			d->collectibles--;
		d->map[d->position.y - 1][d->position.x] = 'P';
		d->map[d->position.y][d->position.x] = '0';
		position(d);
	}
	else if (d->map[d->position.y - 1][d->position.x] == 'E'
		&& d->collectibles == 0)
	{
		exit(0);
	}
}

int	key_hook(int keycode, t_vars *d)
{
	if (keycode == 2)
		draw_d(d);
	else if (keycode == 0)
		draw_a(d);
	else if (keycode == 1)
		draw_s(d);
	else if (keycode == 53)
		exit(0);
	else if (keycode == 13)
		draw_w(d);
	return (0);
}
