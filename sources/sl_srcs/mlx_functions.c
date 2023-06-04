/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:16:19 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/31 10:16:19 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_imgs(t_data *data)
{
	data->img_0 = mlx_xpm_file_to_image(data->mlx, "./img/floor.xpm", &data->width, &data->height);
	data->img_1 = mlx_xpm_file_to_image(data->mlx, "./img/wall.xpm", &data->width, &data->height);
	data->img_B = mlx_xpm_file_to_image(data->mlx, "./img/broken.xpm", &data->width, &data->height);
	data->img_C = mlx_xpm_file_to_image(data->mlx, "./img/house.xpm", &data->width, &data->height);
	data->img_E = mlx_xpm_file_to_image(data->mlx, "./img/exit.xpm", &data->width, &data->height);
	data->img_P = mlx_xpm_file_to_image(data->mlx, "./img/player.xpm", &data->width, &data->height);
	data->img_end = mlx_xpm_file_to_image(data->mlx, "./img/end.xpm", &data->width, &data->height);
}

void	start_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
	{
		ft_printf("Error:\nCould not mlx_init -> Program interrupted\n");
		ft_free_tab(data->map, data->copy_map);
		exit(EXIT_FAILURE);
	}
	return ;
}

void	create_window(t_data *data, char *name)
{
	if (ft_strlen(data->map[0]) < 15 && ft_tablen(data->map) < 11)
	{
		data->img_x = ft_strlen(data->map[0]) * 64;
		data->img_y = ft_tablen(data->map) * 64;
	}
	else
	{
		data->img_x = 15 * 64;
		data->img_y = 11 * 64;
	}
	data->win = mlx_new_window(data->mlx, data->img_x, data->img_y, name);
	if (data->win == NULL)
	{
		ft_printf("Error:\nCould not mlx_new_window -> Program interrupted\n");
		ft_free_tab(data->map, data->copy_map);
		exit(EXIT_FAILURE);
	}
	return ;
}

void	create_image(t_data *data)
{
	data->height = 64;
	data->width = 64;
	if (data->img == NULL)
		data->img = mlx_new_image(data->mlx, 700, 700);
	if (data->img == NULL)
	{
		ft_printf("Error:\nCould not mlx_new_image -> Program interrupted\n");
		ft_free_tab(data->map, data->copy_map);
		exit(EXIT_FAILURE);
	}
	return ;
}
