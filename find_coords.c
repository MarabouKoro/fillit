/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_coords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:28:58 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/08 14:01:18 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_pos(char **square, int letter)
{
	int		pos;
	int		line;

	pos = 0;
	line = 0;
	while (square[line])
	{
		while (square[line][pos])
		{
			if (square[line][pos] == letter)
				return (pos);
			pos++;
		}
		pos = 0;
		line++;
	}
	return (-1);
}

int		find_line(char **square, int letter)
{
	int		pos;
	int		line;

	pos = 0;
	line = 0;
	while (square[line])
	{
		while (square[line][pos])
		{
			if (square[line][pos] == letter)
				return (line);
			pos++;
		}
		pos = 0;
		line++;
	}
	return (-1);
}
