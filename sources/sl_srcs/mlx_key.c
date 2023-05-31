/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:56:15 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/31 16:05:35 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_pressed(int key, t_data *data)
{
	if (key == 124)
	{
		
	}
	if (key == 123)
	{

	}
	if (key == 126)
	{

	}
	if (key == 125)
	{

	}
	if (key == 53)
	{
		ft_printf("Exiting...\n");
		mlx_destroy_window(data->mlx, data->win);
		ft_free_tab(data->map, data->copy_map);
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

int	deal_key(t_data *data)
{
	(void)data;
	return (0);
}