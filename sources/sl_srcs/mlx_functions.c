/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:12:14 by marvin            #+#    #+#             */
/*   Updated: 2023/05/25 23:08:09 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "so_long.h"

int	deal_key(t_data *data)
{
	(void)data;
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
