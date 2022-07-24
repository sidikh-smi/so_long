/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   det_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 06:13:28 by skhaliff          #+#    #+#             */
/*   Updated: 2022/07/24 14:41:25 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
			return (i);
		i++;
	}
	return (0);
}

void	det_error(char *s, t_vars *d)
{
	int	fd;
	int	i;

	i = is(s);
	if (ft_strcmp(s + i, ".ber") != 0)
		error("MAP INVALID");
	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		printf("fd invalid \n");
		exit(1);
	}
	check(d, fd);
	printf ("{HELLO} 2\n");
	check_component(d);
}
