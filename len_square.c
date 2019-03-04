/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 03:45:04 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/04 04:23:55 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		len_square(char **square, int nb_tetri)
{
	int		i;
	int		pos;
	int		line;
	int		max_pos;

	i = 0;
	pos = 0;
	line = 0;
	max_pos = 0;
	while (i < nb_tetri * 4)
	{
		while (square[line][pos])
		{
			if (square[line][pos] != '.')
			{
				i++;
				if (pos > max_pos)
					max_pos = pos;
			}
			pos++;
		}
		line++;
		pos = 0;
	}
	if (max_pos > line)
		return (max_pos + 1);
	return (line);
}
