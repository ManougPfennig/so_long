/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:47:28 by mapfenni          #+#    #+#             */
/*   Updated: 2023/06/03 19:25:11 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_victory(t_data *data)
{
	int	i;

	i = 0;
	ft_printf("Congratulations !\n", data->moves);
	ft_printf("-> You finished in %i moves.\n", data->moves);
	data->victory = 1;
}

int	ft_destroy_windows(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_printf("Exiting...\n");
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_free_tab(char **tab, char **tab2)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	while (tab2 && tab2[i])
	{
		free(tab2[i]);
		i++;
	}
	if (tab2)
		free(tab2);
	tab = NULL;
	tab2 = NULL;
	return ;
}
