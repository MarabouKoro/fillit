/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:03:09 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/03 22:02:16 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

static char	*tetri_maker(int fd)
{
	char		*line;
	char		*str;
	int			i;
	int			j;
	int			ret;
	static int	nb_line = 0;

	i = 0;
	j = 0;
	str = ft_strnew(16);
	while ((ret = ft_read(fd, &line)) > 0)
	{
		if (valid_line(line, nb_line) == 1)
			exit(1);
		if (line[0] == '\n')
		{
			nb_line = 0;
			return (str);
		}
		while (i < 4)
			str[j++] = line[i++];
		i = 0;
		nb_line++;
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
	tab[i] = NULL;
	return (tab);
}
