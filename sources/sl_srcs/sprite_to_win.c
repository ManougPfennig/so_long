/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_to_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:46:43 by mapfenni          #+#    #+#             */
/*   Updated: 2023/06/04 20:52:29 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprite_to_win(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, img, (x * 64), (y * 64));
}

void	fill_background(t_data *data)
{
	int	x;
	int	y;
	
	y = 11;
	while (y--)
	{
		x = 15;
		while (x--)
		{
			sprite_to_win(data, data->img_0, x, y);
		}
	}
}

void	put_map(t_data *data)
{
	int		x;
	int		y;
	char	**minimap;

	minimap = compute_minimap(data);
	fill_background(data);
	y = 0;
	while (minimap[y] != NULL)
	{
		x = 0;
		while (minimap[y][x] != '\0')
		{
			if (minimap[y][x] == '1')
				sprite_to_win(data, data->img_1, x, y);
			else if (minimap[y][x] == '0' || data->map[y][x] == 'P')
				sprite_to_win(data, data->img_0, x, y);
			else if (minimap[y][x] == 'E')
				sprite_to_win(data, data->img_E, x, y);
			else if (minimap[y][x] == 'C')
				sprite_to_win(data, data->img_C, x, y);
			else if (minimap[y][x] == 'B')
				sprite_to_win(data, data->img_B, x, y);
			x++;
		}
		y++;
	}
	put_player(data);
	ft_free_tab(minimap, NULL);
}

void	put_player(t_data *data)
{
	if (ft_strlen(data->map[0]) > 15 || ft_tablen(data->map) > 11)
	{
		if (data->play_x < 7 && data->play_y < 5)
			sprite_to_win(data, data->img_P, data->play_x, data->play_y);
		else if (data->play_x < 7)
			sprite_to_win(data, data->img_P, data->play_x, 5);
		else if (data->play_y < 5)
			sprite_to_win(data, data->img_P, 7, data->play_y);
		else
			sprite_to_win(data, data->img_P, 7, 5);
		return ;
	}
	sprite_to_win(data, data->img_P, data->play_x, data->play_y);
}

void	move_player(t_data *data, int x, int y)
{
	if (data->map[data->play_y + y][data->play_x + x] == '1')
		return ;
	else if (data->map[data->play_y + y][data->play_x + x] == '0')
	{
		data->play_y = data->play_y + y;
		data->play_x = data->play_x + x;
	}
	else if (data->map[data->play_y + y][data->play_x + x] == 'B')
	{
		data->play_y = data->play_y + y;
		data->play_x = data->play_x + x;
	}
	else if (data->map[data->play_y + y][data->play_x + x] == 'C')
	{
		data->map[data->play_y + y][data->play_x + x] = 'B';
		data->play_y = data->play_y + y;
		data->play_x = data->play_x + x;
		data->items--;
	}
	else if (data->map[data->play_y + y][data->play_x + x] == 'E')
	{
		data->play_y = data->play_y + y;
		data->play_x = data->play_x + x;
		if (data->items == 0)
			show_victory(data);
	}
	if (!data->victory)
		ft_printf("%i\n", ++data->moves);
	put_map(data);
}
