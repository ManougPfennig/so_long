/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:56:34 by manoug            #+#    #+#             */
/*   Updated: 2023/05/26 01:49:19 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "so_long.h"

void	flood_test(t_data *data, char **tab, int x, int y)
{
	if (tab[x][y] == 'X' || tab[x][y] == '1')
		return ;
	if (tab[x][y] == 'C')
		data->items--;
	if (tab[x][y] == 'E')
		data->usable = 1;
	tab[x][y] = 'X';
	flood_test(data, tab, (x + 1), y);
	flood_test(data, tab, (x - 1), y);
	flood_test(data, tab, x, (y - 1));
	flood_test(data, tab, x, (y + 1));
}

int	flood_fill(t_data *data)
{
	flood_test(data, data->copy_map, data->start_x, data->start_y);
	ft_free_tab(data->copy_map, NULL);
	if (data->usable == 1 && data->items == 0)
		return (0);
	return (ft_printf("Error\nMap can not be finished"));
}

void	print_map(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return ;
}
	// system("clear");
	// print_map(tab);
	// usleep(10000);