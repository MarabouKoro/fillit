/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 02:08:30 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/05 03:39:34 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		len_tetri(char *tetri)
{
	int		i;
	int		pos;
	int		max_pos;

	i = 0;
	pos = 0;
	max_pos = 0;
	while (tetri[i])
	{
		if (pos == 4)
			pos = 0;
		if (tetri[i] == '#' && pos > max_pos)
			max_pos = pos;
		pos++;
		i++;
	}
	return (max_pos + 1);
}

int		width_tetri(char *tetri)
{
	int		i;
	int		bloc;

	i = 0;
	bloc = 4;
	while (bloc > 0)
	{
		if (tetri[i] == '#')
			bloc--;
		i++;
	}
	return (((i - 1)/ 4) + 1);
}
