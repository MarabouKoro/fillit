/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:10:11 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/10 19:37:05 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**put_tetri(char **square, char *tetri, t_struct2 *st, int letter)
{
	int			i;
	int			init_pos;

	i = 0;
	init_pos = st->pos;
	if (cs(square, tetri, st->line, st->pos) == 1)
		return (NULL);
	while (tetri[i])
	{
		if (tetri[i] != '.')
			square[st->line][st->pos] = letter;
		st->pos++;
		i++;
		if (i % 4 == 0)
		{
			st->line++;
			st->pos = init_pos;
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

static char	**cant_put(char **square, char **array, t_struct2 *st, int size)
{
	st->line = 0;
	if (size != 0)
	{
		st->i--;
		if (find_pos(square, 65 + st->i) == -1)
			return (NULL);
		if (find_pos(square, 65 + st->i) + len_tetri(array[st->i]) > size)
		{
			st->pos = 0;
			st->line = find_line(square, 65 + st->i) + 1;
		}
		else
		{
			st->pos = find_pos(square, 65 + st->i) + 1;
			st->line = find_line(square, 65 + st->i);
		}
		square = remove_tetri(square, 65 + st->i);
	}
	if (size == 0)
		st->i++;
	return (square);
}

static char	**solve(char **sq, char **array, int s)
{
	t_struct2	st;

	st.i = 0;
	st.init_size = s;
	st.pos = 0;
	st.line = 0;
	while (array[st.i])
	{
		while (st.line + width_tetri(array[st.i]) <= s)
		{
			while (st.pos + len_tetri(array[st.i]) <= s)
			{
				if (cs(sq, array[st.i], st.line, st.pos) == 0 && (s = 0) == 0)
					sq = put_tetri(sq, array[st.i], &st, 65 + st.i);
				st.pos++;
			}
			st.pos = 0;
			st.line++;
		}
		if ((sq = cant_put(sq, array, &st, s)) == NULL)
			return (NULL);
		s = st.init_size;
	}
	return (sq);
}

char		**final_square(char **square, char **array)
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
