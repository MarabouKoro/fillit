/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 02:52:22 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/03 05:06:02 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

char	**init_square(void)
{
	int		i;
	int		j;
	char	*line;
	char	**square;

	i = 0;
	if (!(square = (char **)malloc(sizeof(char *) * 105)))	//free(square) ?
		return (NULL);
	while (i < 104)
	{
		j = 0;
		line = ft_strnew(105);								//free(line) ?
		while (j < 104)
			line[j++] = '.';
		line[j] = '\0';
		square[i] = line;
		i++;
	}
	square[i] = NULL;
	return (square);
}
