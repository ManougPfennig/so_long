/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:21:58 by marvin            #+#    #+#             */
/*   Updated: 2023/05/25 18:38:39 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "so_long.h"

char	*get_string_map(int fd)
{
	int		ret;
	char	*buffer;
	char	*str;

	ret = 1;
	str = NULL;
	while (ret > 0)
	{
		buffer = ft_calloc(2, sizeof(char));
		if (!buffer)
			return (NULL);
		ret = read(fd, buffer, 1);
		str = ft_strjoin(str, buffer);
	}
	return (str);
}

void	ft_free(char *str, char *str2)
{
	if (str != NULL)
		free(str);
	if (str2 != NULL)
		free(str2);
	str = NULL;
	str2 = NULL;
	return ;
}