/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:05:24 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/11 15:54:34 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_diese(char *s, int line)
{
	int			i;
	static int	nb_diese = 0;

	i = 0;
	if (line == 4)
		nb_diese = 0;
	while (s[i])
	{
		if (s[i] == '#')
			nb_diese++;
		i++;
	}
	return (nb_diese);
}

static int	valid_char(int pos, char c, int line)
{
	if (line >= 0 && line < 4)
	{
		if (pos >= 0 && pos < 4 && (c == '.' || c == '#'))
			return (0);
		else if (pos == 4 && c == '\n')
			return (0);
	}
	if (line == 4 && pos == 0 && c == '\n')
		return (0);
	return (1);
}

int			valid_line(char *s, int line)
{
	int		i;
	int		nb_diese;

	i = 0;
	nb_diese = check_diese(s, line);
	while (s[i] != '\n')
	{
		if (valid_char(i, s[i], line) == 1)
			return (1);
		i++;
	}
	if (valid_char(i, s[i], line) == 1)
		return (1);
	if (nb_diese > 4 || (line == 3 && nb_diese != 4))
		return (1);
	return (0);
}
