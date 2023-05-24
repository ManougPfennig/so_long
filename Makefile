# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 13:49:45 by mapfenni          #+#    #+#              #
#    Updated: 2023/05/24 14:47:24 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c ./sources/so_long/*.c

OBJS = ${SRCS:.c=.o}

${NAME}: ${OBJS}
	make -C ./sources/ft_printf
	gcc -Wall -Wextra -Werror -lm -lmlx -framework OpenGL -framework AppKit \
	${OBJS} ./sources/ft_printf/libftprintf.a -o ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS} ${BONUS}
	make clean -C ./sources/ft_printf

fclean: clean
	rm -f ${NAME}
	make clean -C ./sources/ft_printf

re: fclean all
	make fclean -C ./sources/ft_printf