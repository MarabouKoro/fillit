/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 04:15:06 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/04 01:17:57 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_space(char **square, char *tetri, int line, int pos)
{
	int		i;
	int		init_pos;

	i = 0;
	init_pos = pos;
	while (tetri[i])
	{
		if (tetri[i] == '#' && square[line][pos] != '.')
			return (1);
		pos++;
		i++;
		if (i % 4 == 0)
		{
			line++;
			pos = init_pos;
		}
	}
	return (0);
}

char		**put_tetri(char **square, char *tetri, int line, int pos, int letter)
{
	int		i;
	int		init_pos;

	i = 0;
	init_pos = pos;
	if (check_space(square, tetri, line, pos) == 1)
		return (NULL);
	while (tetri[i])
	{
		if (tetri[i] != '.')
			square[line][pos] = letter;
		pos++;
		i++;
		if (i % 4 == 0)
		{
			line++;
			pos = init_pos;
		}
	}
	return (square);
}
