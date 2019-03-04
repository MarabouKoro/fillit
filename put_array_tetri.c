/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_array_tetri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 06:02:03 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/04 06:02:23 by jcreux           ###   ########.fr       */
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

static char	**put_tetri(char **square, char *tetri, int line, int pos, int letter)
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

char		**put_array_tetri(char **square, char **array_tetri)
{
	int		i;
	int		line;
	int		pos;
	int		letter;
	char	**old_square;

	i = 0;
	line = 0;
	pos = 0;
	letter = 65;
	old_square = square;
	while (array_tetri[i])
	{
		square = put_tetri(square, array_tetri[i], line, pos, letter);
		while (square == NULL)
		{
			square = old_square;
			pos++;
			square = put_tetri(square, array_tetri[i], line, pos, letter);
		}
		letter++;
		pos = 0;
		i++;
	}
	return (square);
}
