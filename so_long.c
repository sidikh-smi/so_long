/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 01:36:55 by skhaliff          #+#    #+#             */
/*   Updated: 2022/07/23 15:00:59 by skhaliff         ###   ########.fr       */
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
	}
}
