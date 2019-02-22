/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:17:22 by jcreux            #+#    #+#             */
/*   Updated: 2019/02/22 01:19:12 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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
