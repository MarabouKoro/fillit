/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_tetri.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 04:51:09 by jcreux            #+#    #+#             */
/*   Updated: 2019/02/21 04:55:20 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

int		count_tetri(char *s)
{
	int			i;
	static char	*tetri_array[19] = {O, I, I_R, T, T_R, H_L, H_R, S, Z, A_L,
									A_R, L, L_R, J, J_R, L2, L2_R, J2, J2_R};

	i = 0;
	while (i < 19)
	{
		if (ft_strstr(s, tetri_array[i]))
		{
			printf("%d -- %s\n", 0, tetri_array[i]);
			//return (0);
		}
		printf("%d -- %s\n", 1, tetri_array[i]);
		i++;
	}
	return (1);
}
