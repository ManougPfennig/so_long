/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:54:08 by mapfenni          #+#    #+#             */
/*   Updated: 2023/05/23 17:21:51 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	return (s);
}

char	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (count && SIZE_MAX / count < size)
		return (NULL);
	str = malloc(count * size);
	if (!(str))
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}
