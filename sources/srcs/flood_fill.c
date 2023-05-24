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

void flood_fill(t_data *data, int x, int y)
{
    if (x < 0 || y < 0)
        return ;
    if (data->copy_map[x] == NULL || data->copy_map[x][y] == '\0')
        return;
    if (data->copy_map[x][y] == 'F' || data->copy_map[x][y] == '1')
        return;
}