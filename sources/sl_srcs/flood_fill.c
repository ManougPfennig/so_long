/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:56:34 by manoug            #+#    #+#             */
/*   Updated: 2023/05/25 17:19:25 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "so_long.h"

void	flood_test(t_data *data, char **tab, int x, int y)
{
	if (tab[x][y] == 'F' || tab[x][y] == '1')
		return ;
	if (tab[x][y] == 'C')
		data->items--;
	if (tab[x][y] == 'E')
		data->usable = 1;
	tab[x][y] = 'F';
	flood_test(data, tab, ++x, y);
	flood_test(data, tab, --x, y);
	flood_test(data, tab, x, ++y);
	flood_test(data, tab, x, --y);
}

int	flood_fill(t_data *data)
{
	flood_test(data, data->copy_map, data->start_x, data->start_y);
	if (data->usable == 1 && data->items == 0)
		return (0);
	return (ft_printf("Error\nMap can not be finished"));
}

	// system("clear");
	// print_map(tab);
	// usleep(200);
void	print_map(char **tab)
{
	int	i;
	int	y;

	i = 0;
	while (tab[i] != NULL)
	{
		y = 0;
		while (tab[i][y] != '\0')
		{
			printf("[%d]", tab[i][y]);
			y++;
		}
		printf("\n");
		i++;
	}
	return ;
}