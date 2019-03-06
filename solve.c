/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:10:11 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/06 17:21:51 by jcreux           ###   ########.fr       */
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

char		**solve(char **square, char **array_tetri)
{
	int		i;
	int		pos;
	int		line;
	int		len;
	int		a = 0;

	i = 0;
	pos = 0;
	line = 0;
	len = len_square(count_tetri(array_tetri));
	while (array_tetri[i])
	{
		while (line + width_tetri(array_tetri[i]) <= len)
		{
			while (pos + len_tetri(array_tetri[i]) <= len)
			{
				if (check_space(square, array_tetri[i], line, pos) == 0 && a == 0)
				{
					square = put_tetri(square, array_tetri[i], line, pos, 65 + i);
					a = 1;
				}
				pos++;
			}
			pos = 0;
			line++;
		}
		a = 0;
		line = 0;
		i++;
	}
	return (square);
}
