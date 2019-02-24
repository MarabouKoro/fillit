/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:05:24 by jcreux            #+#    #+#             */
/*   Updated: 2019/02/24 19:32:28 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	valid_char(int pos, char c, int nb_line)
{
	static int	nb_diese = 0;

	if ((pos >= 0 && pos <= 3) && (c == '#' || c == '.'))
	{
		if (c == '#')
			nb_diese++;
		return (0);
	}
	if (pos == 4 && c == '\n')
	{
		if (nb_line == 4 && nb_diese != 4)
			return (1);
		nb_diese = 0;
		return (0);
	}
	return (1);
}

int			valid_line(char *line)
{
	int			i;
	static int	nb_line = 0;

	i = 0;
	if (nb_line < 4)
	{
		while (i < 4)
		{
			if (valid_char(i, line[i], nb_line) == 1)
				return (1);
			i++;
		}
		if (valid_char(i, line[i], nb_line) == 0)
		{
			nb_line++;
			return (0);
		}
	}
	else
		if (line[0] == '\n' && valid_char(0, '\n', 4) == 0)
		{
			nb_line = 0;
			return (0);
		}
	return (1);
}
