/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 04:15:06 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/03 05:59:58 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**put_tetri(char **square, char *tetri, int line, int pos)
{
	int		i;
	int		init_pos;

	i = 0;
	init_pos = pos;
	while (tetri[i])
	{
		square[line][pos++] = tetri[i++];
		if (i % 4 == 0)
		{
			line++;
			pos = init_pos;
		}
	}
	return (square);
}
