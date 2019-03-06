/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:18:32 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/06 15:56:38 by jcreux           ###   ########.fr       */
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

char	*init_square(char **array_tetri)
{
	int		i;
	int		len;
	char	*square;

	i = 0;
	len = len_square(count_tetri(array_tetri));
	if (!(square = (char *)malloc(sizeof(char) * ((len * len) + 1))))
		return (NULL);
	while (i < (len * len))
	{
		square[i] = '.';
		i++;
	}
	square[i] = '\0';
	return (square);
}
