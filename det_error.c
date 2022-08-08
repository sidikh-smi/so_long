/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   det_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 06:13:28 by skhaliff          #+#    #+#             */
/*   Updated: 2022/08/06 12:44:52 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	isber(char *s)
{
	int	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == '.' )
			return (i);
		i--;
	}
	return (0);
}

void	check_walls(t_vars *d)
{
	int	i;

	i = 1;
	while (d->map[i])
	{
		if (d->map[i][0] != '1' || d->map[i][ft_strlen(d->map[0]) - 1] != '1')
			error("Suround WAALLLL!!!!");
		i++;
	}
}

void	check_rectangle(t_vars *d)
{
	int	i;

	i = 0;
	while (d->map[i])
	{
		if (ft_strlen(d->map[i]) != ft_strlen(d->map[0]))
			error("It's not rectangle");
		i++;
	}
	d->map_height = i;
	if (ft_strlen(d->map[0]) == i)
		error("It's not rectangle");
}

void	det_error(char *s, t_vars *d)
{
	int	fd;
	int	i;

	i = isber(s);
	if (ft_strcmp(s + i, ".ber") != 0)
		error("MAP INVALID");
	fd = open(s, O_RDONLY);
	if (fd < 0)
		error("fd invalid");
	check(d, fd);
	check_rectangle(d);
	check_walls(d);
	check_component(d);
}
