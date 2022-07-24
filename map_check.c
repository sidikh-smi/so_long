/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:15:13 by skhaliff          #+#    #+#             */
/*   Updated: 2022/07/23 15:00:45 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	components(char *h)
{
	int	i;

	i = 0;
	while (h[i])
	{
		if (h[i] != '0' && h[i] != '1' && h[i] != 'P'
			&& h[i] != 'C' && h[i] != 'E' && h[i] != '\n')
			error("CONPONEMENT INV");
		i++;
	}
}

void	check(t_vars *s, int fd)
{
	char	*h;
	char	*e;

	s->map = NULL;
	e = NULL;
	h = get_next_line(fd);
	while (h)
	{
		components(h);
		e = ft_strjoin(e, h);
		free (h);
		h = get_next_line(fd);
	}
	if (e)
	{
		s->map = ft_split(e, '\n');
		free(e);
	}
	close(fd);
}
