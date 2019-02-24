/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:05:24 by jcreux            #+#    #+#             */
/*   Updated: 2019/02/24 20:46:53 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//ft_nb_diese

static int	valid_char(int pos, char c, int nb_line)
{
	static int	nb_diese = 0;

	if ((pos >= 0 && pos <= 3) && (c == '#' || c == '.'))
	{
		if (c == '#')
			printf("%d - ", nb_diese);
			nb_diese++;
		return (0);
	}
	if (pos == 4 && c == '\n')
	{
		return (0);
	}
	if (nb_line == 4 && pos == 0 && c == '\n')
	{
		if (nb_diese == 4)
		{
			printf("%d - ", nb_diese);
			nb_diese = 0;
			return (0);
		}
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
	if (line[0] == '\n' && nb_line == 4)
	{
		nb_line = 0;
		return (0);
	}
	return (1);
}
