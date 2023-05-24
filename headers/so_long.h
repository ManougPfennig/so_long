/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:40:40 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/24 14:23:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <mlx.h>
# include "ft_printf.h"
# include <math.h>

# define UI_MAX 4294967295

typedef struct	s_data {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx;
	void			*win;
	int				x;
	int				y;
	int				dir;
	int				left;
	int				right;
	int				up;
	int				down;
	int				size;
	unsigned int	color;
	char			**map;
	char			**copy_map;
	int				items;
	int				start_x;
	int				start_y;
}				t_data;

int				main(int ac, char **av);
int				ft_strcmp(char *str, char *str2);
int				arg_parsing(int ac, char **av, t_data *data);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				deal_key(t_data *params);
void			generate_mandelbrot(t_data *data);
int				key_release(int key, t_data *data);
int				key_pressed(int key, t_data *data);
int				ft_destroy_windows(t_data *data);
unsigned int	new_color(t_data *data);
char			*ft_calloc(size_t count, size_t size);
void			*ft_bzero(void *s, size_t n);
int				check_map(char *name, t_data *data);
int				ft_strlen(char *str);
int				ft_tablen(char **tab);
int				check_walls(char **tab);
int				flood_fill(t_data *data);
int				check_CEP(char **tab, t_data *data);

#endif