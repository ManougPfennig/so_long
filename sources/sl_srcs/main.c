/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:40:02 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/24 17:08:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;
	if (arg_parsing(ac, av, &data))
		exit(EXIT_FAILURE);
	// data.dir = 1;
	// data.size = 20;
	// data.mlx = mlx_init();
	// if (data.mlx == NULL)
	// {
	// 	ft_printf("Error: Could not mlx_init -> Program interrupted\n");
	// 	exit(EXIT_FAILURE);
	// }
	// data.win = mlx_new_window(data.mlx, 1000, 700, av[1]);
	// if (data.win == NULL)
	// {
	// 	ft_printf("Error: Could not mlx_new_window -> Program interrupted\n");
	// 	exit(EXIT_FAILURE);
	// }
	// data.color = 0x00000000;
	// data.x = 500;
	// data.y = 350;
	// data.img = mlx_new_image(data.mlx, 1000, 700);
	// data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, \
	// &data.endian);
	// my_mlx_pixel_put(&data, data.x, data.y, new_color(&data));
	// mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	// mlx_hook(data.win, 2, 1L << 0, key_pressed, &data);
	// mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	// mlx_loop_hook(data.mlx, deal_key, &data);
	// // mlx_hook(data.win, 17, 0, ft_destroy_windows, &data);
	// // mlx_key_hook(data.win, deal_key, &data);
	// // generate_triangle(&data);
	// mlx_loop(data.mlx);
	exit(EXIT_SUCCESS);
}


