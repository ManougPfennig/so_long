/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:39:36 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/24 14:28:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	arg_parsing(int ac, char **av, t_data *data)
{
	if (ac > 2 || ac < 2)
	{
		ft_printf("Please start program with \
		the name of the map as only argument\n");
		return (1);
	}
	if (ac == 2)
	{
		ft_printf("Checking map...\n", av[1]);
		return (check_map(av[1], data));
	}
	return (0);
}

int	check_map(char *name, t_data *data)
{
	int		i;
	int		n;
	char	*str;

	str = ".ber";
	i = ft_strlen(name);
	n = 4;
	while (n--)
	{
		if (name[i - 1] != str[n])
			return (ft_printf("Error\nWrong map format, please use '.ber'"));
		i--;
	}
	data->map = ft_split_read(name);
	data->copy_map = ft_split_read(name);
	if (data->map == NULL || check_walls(data->map))
		return (1);
	if (check_CEP(data->map, data))
		return (1);
	if (flood_fill(data->copy_map, 0, 0))
		return (1);
	return (0);
}

int	check_walls(char **tab)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	x = ft_strlen(tab[0]);
	while (tab[y] != NULL)
	{
		if (x != ft_strlen(tab[y]))
			return (ft_printf("Error\nPlease use a rectangular map"));
		y++;
	}
	i = 0;
	while (x--)
	{
		if (tab[0][x] != '1' || tab[ft_tablen(tab) - 1][x] != '1')
			return (ft_printf("Error\nMap is missing walls"));
	}
	while (y--)
	{
		if (tab[y][0] != '1' || tab[y][ft_strlen[tab[y]] - 1] != '1')
			return (ft_printf("Error\nMap is missing walls"));
	}
	return (0);
}

int	check_CEP(char **tab, t_data *data)
{
	int	i;
	int	y;
	int	C;
	int	EP;

	y = 0;
	while (tab[y] != NULL)
	{
		i = 0;
		while(tab[y][i] != '\0')
		{
			if (tab[y][i] == 'E' || tab[y][i] == 'P')
				EP++;
			if (tab[y][i] == 'C')
				C++;
			if (tab[y][i] == 'P')
			{
				data->start_x = y;
				data->start_y = i;
			}
			i++;
		}
		y++;
	}
	if (EP != 2)
		return (ft_printf("Error\nInvalid amount of Exit or Starting position"));
	if (C < 1)
		return (ft_printf("Error\nMap must have at least one item"));
	data->items = C;
	return (0);
}