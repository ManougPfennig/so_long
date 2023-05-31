/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_pixel_and_key.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:56:15 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/31 11:20:17 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int	key_pressed(int key, t_data *data)
{
	if (key == 124)
	{
		data->x++;
		my_mlx_pixel_put(data, data->x, data->y, 0x25500000);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	if (key == 123)
	{
		data->x--;
		my_mlx_pixel_put(data, data->x, data->y, 0x25500000);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	if (key == 126)
	{
		data->y--;
		my_mlx_pixel_put(data, data->x, data->y, 0x25500000);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	if (key == 125)
	{
		data->y++;
		my_mlx_pixel_put(data, data->x, data->y, 0x25500000);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	if (key == 53)
	{
		ft_printf("Exiting...\n");
		mlx_destroy_window(data->mlx, data->win);
		exit(EXIT_SUCCESS);
	}
	// if (key == 17)
	// 	ft_destroy_windows(data);
	return (0);
}

int	key_release(int key, t_data *data)
{
	(void)key;
	(void)data;
	return (0);
}
