# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 13:49:45 by mapfenni          #+#    #+#              #
#    Updated: 2023/06/04 19:49:48 by mapfenni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = ./sources/sl_srcs/flood_fill.c ./sources/sl_srcs/ft_function.c \
./sources/sl_srcs/ft_function3.c ./sources/sl_srcs/main.c \
./sources/sl_srcs/mlx_key.c ./sources/sl_srcs/free_end.c \
./sources/sl_srcs/ft_function2.c ./sources/sl_srcs/ft_split_read.c \
./sources/sl_srcs/mlx_functions.c ./sources/sl_srcs/so_long_parsing.c \
./sources/sl_srcs/mlx_sprite.c ./sources/sl_srcs/sprite_to_win.c \
./sources/sl_srcs/compute_minimap.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

${NAME}: ${OBJS}
	make -C ./sources/ft_printf
	gcc ${CFLAGS} ${OBJS} ./sources/ft_printf/libftprintf.a -lm -lmlx -framework OpenGL -framework AppKit -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS} ${BONUS}
	make clean -C ./sources/ft_printf

fclean: clean
	rm -f ${NAME}
	make clean -C ./sources/ft_printf

re: fclean all
	make fclean -C ./sources/ft_printf