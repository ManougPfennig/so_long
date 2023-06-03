/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:46:43 by mapfenni          #+#    #+#             */
/*   Updated: 2023/06/03 15:28:28 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			x++;
		}
		y++;
	}
}