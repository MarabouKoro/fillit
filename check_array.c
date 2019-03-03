/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 23:33:44 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/03 01:46:45 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

static int	find_tetri(char *s)
{
	int			i;
	static char	*tetri_array[19] = {O, I, IR, T, TR, HL, HR, S, Z, AL,
									AR, L, LR, J, JR, L2, L2R, J2, J2R};

	i = 0;
	while (i < 19)
	{
		if (ft_strstr(s, tetri_array[i]))
			return (i);
		i++;
	}
	return (-1);
}

/*
int			*count_tetri(char *s[])
{
	int			i;
	static int	nb_tetri_array[19] = {0};

	i = 0;
	while (s[i])
	{
		if (find_tetri(s[i]) != -1)
			nb_tetri_array[find_tetri(s[i])]++;
		i++;
	}
	return (nb_tetri_array);
}
*/

char	**check_array(char **array)
{
	int		i;
	static char	*tetri_array[19] = {O, I, IR, T, TR, HL, HR, S, Z, AL,
									AR, L, LR, J, JR, L2, L2R, J2, J2R};

	i = 0;
	while (array[i])
	{
		if (find_tetri(array[i]) == -1)
			exit(1);
		array[i] = tetri_array[find_tetri(array[i])];
		i++;
	}
	return (array);
}
