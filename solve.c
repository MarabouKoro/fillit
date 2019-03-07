/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:10:11 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/07 18:20:52 by jcreux           ###   ########.fr       */
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

static char **remove_tetri(char **square, int letter)
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

static char	**move_tetri(char **square, char *tetri, int letter)
{
	int		line;
	int		pos;
	int		a;
	char	**old_square;
	int		i;
	int		init_pos;

	line = 0;
	pos = 0;
	a = 0;
	i = 0;
	while (square[line])
	{
		while (square[line][pos])
		{
			if (square[line][pos] == letter)	
				a = 1;
			if (a == 1)
				break;
			pos++;
		}
		if (a == 1)
			break;
		pos = 0;
		line++;
	}
	square = remove_tetri(square, letter);
	old_square = square;
	init_pos = pos;
	while ((square = put_tetri(old_square, tetri, line, pos, letter)) == NULL)
	{
		pos++;
		if (i == 4)
		{
			pos = init_pos;
			line++;
			i = 0;
		}
		i++;

	}
	return (square);
}

char		**solve(char **square, char **array)
{
	int		i;
	int		pos;
	int		line;
	int		size;

	i = 0;
	pos = 0;
	line = 0;
	while (array[i])
	{
		size = len_square(count_tetri(array));
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
			square = move_tetri(square, array[i], 65 + i);
		}
		i++;
	}
	return (square);
}
