/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:56:15 by mapfenni          #+#    #+#             */
/*   Updated: 2023/06/03 19:30:05 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_pressed(int key, t_data *data)
{
	if (data->victory)
		sprite_to_win(data, "./img/end.xpm", data->play_x, data->play_y);
	else if (key == 13)
	{
		move_player(data, 0, -1);
	}
	else if (key == 0)
	{
		move_player(data, -1, 0);
	}
	else if (key == 1)
	{
		move_player(data, 0, 1);
	}
	else if (key == 2)
	{
		move_player(data, 1, 0);
	}
	if (key == 53)
	{
		ft_printf("Exiting...\n");
		mlx_destroy_window(data->mlx, data->win);
		ft_free_tab(data->map, data->copy_map);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	key_release(int key, t_data *data)
{
	(void)key;
	(void)data;
	return (0);
}

int	deal_key(t_data *data)
{
	(void)data;
	return (0);
}