/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 22:20:42 by jcreux            #+#    #+#             */
/*   Updated: 2019/02/24 05:42:27 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

static char	*tetri_maker(int fd)
{
	char	*line;
	char	*str;
	int		i;
	int		j;
	int		ret;

	i = 0;
	j = 0;
	str = ft_strnew(16);
	while ((ret = ft_read(fd, &line)) > 0)
	{
		if (line[0] == '\n')
			return (str);
		while (i < 4)
			str[j++] = line[i++];
		i = 0;
		if (j == 16)
			str[j] = '\0';
	}
	if (str[0] != '\0')
		return (str);
	if (ret == -1)
		exit(1);
	return (NULL);
}

char		**array_maker(int fd)
{
	char	*str;
	char	**tab;
	int		i;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * 27))) //malloc trop grand / check fichier de 26 tetris / +1
		return (NULL);
	str = tetri_maker(fd);
	while (str != NULL)
	{
		 tab[i] = str;
		 str = tetri_maker(fd);
		 i++;
	}
	return (tab);
}
