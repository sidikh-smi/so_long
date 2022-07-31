# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhaliff <skhaliff@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 20:27:21 by skhaliff          #+#    #+#              #
#    Updated: 2022/07/31 14:25:59 by skhaliff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SO_LONG = so_long
SRCS_SO_LONG = so_long.c det_error.c check_components.c error.c map_check.c ft_strjoin.c get_next_line.c get_next_line_utils.c ft_calloc.c\
			ft_bzero.c ft_printf.c ft_putchar.c ft_putnbr.c ft_split.c ft_itoa.c ft_strlcpy.c ft_strcmp.c init_map.c draw_map.c key_hook.c\
			p_player.c counter.c

CC		= cc
RM		= rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(SO_LONG)

$(SO_LONG):
		$(CC) $(SRCS_SO_LONG) -lmlx -framework OpenGL -framework AppKit -o $(SO_LONG)

clean:
		$(RM) $(SO_LONG)

fclean:	clean

re:		fclean all