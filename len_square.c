/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 03:45:04 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/06 19:06:01 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_sqrt(int n)
{
	int		i;
	int		max;

	i = 0;
	max = n / 2;
	if (n == 1)
		return (1);
	while (i <= max)
	{
		if (i * i == n)
		{
			return (i);
		}
		i++;
	}
	return (0);
}

int			len_square(int nb_tetri)
{
	int		i;

	i = 0;
	while (i >= 0)
	{
		if (ft_sqrt(i) > 0 && i >= nb_tetri * 4)
			return (ft_sqrt(i));
		i++;
	}
	return (0);
}
