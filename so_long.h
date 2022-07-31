/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:27:10 by skhaliff          #+#    #+#             */
/*   Updated: 2022/07/31 14:25:53 by skhaliff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdarg.h>
# define BUFFER_SIZE 42

typedef struct t_deplacement
{
	int	x;
	int	y;
}t_deplacement;

typedef struct t_component
{
	int	nmbr_p;
	int	nmbr_exit;
	int	wall;
	int	nmbr_collectibles;
	int	size;
}t_component;

typedef struct t_vars
{
	void			*mlx;
	void			*win;
	void			*img;
	char			**map;
	void			*col;
	void			*exit;
	void			*player;
	void			*wall;
	void			*bg;
	int				collectibles;
	int				pas;
	int				map_height;
	int				map_width;
	t_deplacement	position;
}t_vars;

int		ft_printf(char *format, ...);
int		ft_putnbr(int n);
int		ft_putchar(const char c);
char	*ft_line(char *s);
char	*ft_itoa(int n);
char	*new_line(char *s);
char	*read_file(int fd, char *s);
char	*get_next_line(int fd);
void	check(t_vars *s, int fd);
void	check_component(t_vars *d);
void	det_error(char *s, t_vars *d);
void	error(char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char *s, int c);
void	ft_bzero(void *s, size_t n);
char	**ft_split(char *s, char c);
char	*ft_strdup(char *s1);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
int		ft_strcmp(const char *s1, const char *s2);
int		key_hook(int keycode, t_vars *d);
void	init_map(t_vars *d);
void	draw(t_vars *d);
void	position(t_vars *d);
void	counter(t_vars *d);

#endif