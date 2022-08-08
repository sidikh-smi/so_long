/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 00:15:13 by skhaliff          #+#    #+#             */
/*   Updated: 2022/08/06 14:43:40 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	empty_map(char *s, t_vars *d)
{
	if (s == NULL)
	{
		free(d->map);
		error("empty map!!");
	}
}

int	ft_size(char *e)
{
	int	i;

	i = 0;
	while (e[i])
	{
		i++;
	}
	return (i);
}

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
	int		i;

	s->map = NULL;
	e = NULL;
	h = get_next_line(fd);
	empty_map(h, s);
	while (h)
	{
		if (h[0] == '\n' || h[0] == '\0')
			error("empty line!!!");
		components(h);
		e = ft_strjoin(e, h);
		free (h);
		h = get_next_line(fd);
	}
	i = ft_size(e);
	if (e[i - 1] == '\n')
		error("empty line");
	s->map = ft_split(e, '\n');
	free(e);
	close(fd);
}
