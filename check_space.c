/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 19:15:43 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/10 19:37:32 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		cs(char **square, char *tetri, int line, int pos)
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
