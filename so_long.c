/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 01:36:55 by skhaliff          #+#    #+#             */
/*   Updated: 2022/07/30 16:58:23 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	*d;

	d = malloc(sizeof(t_vars));
	if (argc != 2)
		error("ERROR");
	if (argc == 2)
	{
		det_error(argv[1], d);
		init_map(d);
		draw(d);
		mlx_loop(d->mlx);
	}
}
