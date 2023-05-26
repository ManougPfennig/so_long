/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:21:58 by marvin            #+#    #+#             */
/*   Updated: 2023/05/26 01:48:00 by marvin           ###   ########.fr       */
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

char *ft_strdup(char *str)
{
	char *new;
	int i;

	i = 0;
	if (!str)
		return (NULL);
	new = malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str && str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}