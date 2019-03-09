/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:10:11 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/09 16:21:11 by jcreux           ###   ########.fr       */
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

static char	**remove_tetri(char **square, int letter)
{
	int		line;
	int		pos;

	line = 0;
	pos = 0;
	while (square[line])
	{
		while (square[line][pos])
		{
			if (square[line][pos] == letter)
				square[line][pos] = '.';
			pos++;
		}
		pos = 0;
		line++;
	}
	return (square);
}

static char	**solve(char **square, char **array, int size)
{
	int		i;
	int		pos;
	int		line;
	int		init_size;

	i = 0;
	pos = 0;
	line = 0;
	init_size = size;
	while (array[i])
	{
		while (line + width_tetri(array[i]) <= size)
		{
			while (pos + len_tetri(array[i]) <= size)
			{
				if (check_space(square, array[i], line, pos) == 0)
				{
					square = put_tetri(square, array[i], line, pos, 65 + i);
					size = -1;
				}
				pos++;
			}
			pos = 0;
			line++;
		}
		line = 0;
		if (size != -1)
		{
			i--;
			if (find_pos(square, 65 + i) == -1)
				return (NULL);
			if (find_pos(square, 65 + i) + len_tetri(array[i]) > size)
			{
				pos = 0;
				line = find_line(square, 65 + i) + 1;
			}
			else
			{
				pos = find_pos(square, 65 + i) + 1;
				line = find_line(square, 65 + i);
			}
			square = remove_tetri(square, 65 + i);
		}
		if (size == -1)
			i++;
		size = init_size;
	}
	return (square);
}

char	**final_square(char **square, char **array)
{
	int		size;
	char	**final_square;

	size = len_square(count_tetri(array));
	final_square = solve(square, array, size);
	while (final_square == NULL)
	{
		size++;
		final_square = solve(new_square(size), array, size);
	}
	return (final_square);
}
