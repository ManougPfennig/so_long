/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:39:36 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/23 17:37:59 by mapfenni         ###   ########.fr       */
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
	return (1);
}

int	check_map(char *name, t_data *data)
{
	data->map = ft_split_read(name);
	
}

int	ft_strcmp(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i] && str2[i])
	{
		if (str[i] != str2[i])
			return (0);
		i++;
	}
	if (str[i] != str2[i])
		return (0);
	return (1);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	deal_key(t_data *data)
{
	return (0);
}