/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_to_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:46:43 by mapfenni          #+#    #+#             */
/*   Updated: 2023/06/03 18:28:09 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprite_to_win(t_data *data, char *file, int x, int y)
{
	data->img = mlx_xpm_file_to_image(data->mlx, file, &data->width, &data->height);
	mlx_put_image_to_window(data->mlx, data->win, data->img, (x * 64), (y * 64));
}

void	put_map(t_data *data)
{
	int	x;
	int	y;
	
	y = 0;
	while (data->map[y] != NULL)
	{
		x = 0;
		while (data->map[y][x] != '\0')
		{
			if (data->map[y][x] == '1')
				sprite_to_win(data, "./img/wall.xpm", x, y);
			else if (data->map[y][x] == '0' || data->map[y][x] == 'P')
				sprite_to_win(data, "./img/floor.xpm", x, y);
			else if (data->map[y][x] == 'E')
				sprite_to_win(data, "./img/exit.xpm", x, y);
			else if (data->map[y][x] == 'C')
				sprite_to_win(data, "./img/house.xpm", x, y);
			else if (data->map[y][x] == 'B')
				sprite_to_win(data, "./img/broken.xpm", x, y);
			put_player(data);
			x++;
		}
		y++;
	}
}

void	put_player(t_data *data)
{
	sprite_to_win(data, "./img/character0.xpm", data->play_x, data->play_y);
}

void	move_player(t_data *data, int x, int y)
{
	if (data->map[data->play_y + y][data->play_x + x] == '1')
		return ;
	else if (data->map[data->play_y + y][data->play_x + x] == '0')
	{
		data->play_y = data->play_y + y;
		data->play_x = data->play_x + x;
		ft_printf("%i\n", ++data->moves);
	}
	else if (data->map[data->play_y + y][data->play_x + x] == 'B')
	{
		data->play_y = data->play_y + y;
		data->play_x = data->play_x + x;
		ft_printf("%i\n", ++data->moves);
	}
	else if (data->map[data->play_y + y][data->play_x + x] == 'C')
	{
		data->map[data->play_y + y][data->play_x + x] = 'B';
		data->play_y = data->play_y + y;
		data->play_x = data->play_x + x;
		data->items--;
		ft_printf("%i\n", ++data->moves);
	}
	else if (data->map[data->play_y + y][data->play_x + x] == 'E')
	{
		data->play_y = data->play_y + y;
		data->play_x = data->play_x + x;
		if (data->items == 0)
			show_victory(data);
		ft_printf("%i\n", ++data->moves);
	}
	put_map(data);
}