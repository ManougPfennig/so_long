/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manoug <manoug@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:56:34 by manoug            #+#    #+#             */
/*   Updated: 2023/05/24 10:56:34 by manoug           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_test(t_data *data, char **tab, int x, int y)
{
	if (tab[x] == NULL || tab[x][y] == '\0')
		return;
	if (tab[x][y] == 'F' || tab[x][y] == '1')
		return;
	if tab[x][y] == 'C'
		data->items--;
	tab[x][y] = 'F';
	flood_test(data, tab, ++x, y);
	flood_test(data, tab, --x, y);
	flood_test(data, tab, x, ++y);
	flood_test(data, tab, x, --y);
}

int	flood_fill(t_data *data)
{
	flood_test(data, data->copy_map, data->start_x, data->start_y);
}