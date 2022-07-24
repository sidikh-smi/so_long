/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_components.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:02:07 by skhaliff          #+#    #+#             */
/*   Updated: 2022/07/24 15:17:00 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_component(t_component *p)
{
	if (p->wall == 0)
		error("WALLLL");
	else if (p->nmbr_p == 0 || p->nmbr_p > 1)
		error("PLAYEER");
	else if (p->nmbr_exit < 1)
		error("EXITTT");
	else if (p->nmbr_collectibles < 1)
		error("COLLECTIBLES");
}

void	init_component(t_component *p, t_vars *d)
{
	p->wall = 1;
	p->nmbr_collectibles = 0;
	p->nmbr_exit = 0;
	p->nmbr_p = 0;
	d->nbln = 0;
	while (d->map[d->nbln])
		d->nbln++;
}

void	check_component(t_vars *d)
{
	int			i;
	int			j;
	t_component	p;

	i = 0;
	init_component(&p, d);
	while (i < ft_strlen(d->map[0]))
	{
		if (d->map[0][i] != '1' ||
			d->map[d->nbln - 1][i] != '1')
				p.wall = 0;
		j = 0;
		while (d->map[j])
		{
			if (d->map[j][i] == 'E')
				p.nmbr_exit++;
			else if (d->map[j][i] == 'C')
				p.nmbr_collectibles++;
			else if (d->map[j][i] == 'P')
				p.nmbr_p++;
			j++;
		}
		i++;
	}
	error_component(&p);
}
