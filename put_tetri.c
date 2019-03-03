/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 04:15:06 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/03 05:15:58 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**put_tetri(char **square, char *tetri, int line, int pos)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tetri[i])
	{
		square[line][pos++] = tetri[i++];
		if (pos == 4)
		{
			line++;
			pos = 0;
		}
	}
	return (square);
}
