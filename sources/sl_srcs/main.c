/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:16:14 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/31 16:07:02 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (arg_parsing(ac, av, &data))
		exit(EXIT_FAILURE);
	start_mlx(&data);
	create_window(&data, av[1]);
	create_image(&data);
	printf("%i\n", data.img_x);
	printf("%i\n", data.img_y);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
	&data.endian);
	data.img = mlx_xpm_file_to_image(data.mlx, "./sources/img/character0.xpm", &data.width, &data.height);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 2, 1L << 0, key_pressed, &data);
	mlx_hook(data.win, 3, 1L << 1, key_release, &data);
	mlx_loop_hook(data.mlx, deal_key, &data);
	mlx_hook(data.win, 17, 0, ft_destroy_windows, &data);
	mlx_key_hook(data.win, deal_key, &data);
	mlx_loop(data.mlx);
	ft_free_tab(data.map, data.copy_map);
	exit(EXIT_SUCCESS);
}


