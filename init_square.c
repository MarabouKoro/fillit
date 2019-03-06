/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:18:32 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/06 16:57:07 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

int		count_tetri(char **array_tetri)
{
	int		i;

	i = 0;
	while (array_tetri[i])
		i++;
	return (i);
}

char	**init_square(char **array_tetri)
{
	int		i;
	int		j;
	int		len;
	char	*s;
	char	**square;

	i = 0;
	len = len_square(count_tetri(array_tetri));
	if (!(square = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		j = 0;
		if (!(s = (char *)malloc(sizeof(char) * (len + 2))))
			return (NULL);
		while (j < len)
		{
			s[j] = '.';
			j++;
		}
		s[j++] = '\n';
		s[j] = '\0';
		square[i] = s;
		i++;
	}
	square[i] = NULL;
	return (square);
}
