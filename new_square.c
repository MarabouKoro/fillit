/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 18:09:44 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/07 18:46:32 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

char	**new_square(int size)
{
	int		i;
	int		j;
	char	*s;
	char	**square;

	i = 0;
	if (!(square = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		j = 0;
		if (!(s = (char *)malloc(sizeof(char) * (size + 2))))
			return (NULL);
		while (j < size)
			s[j++] = '.';
		s[j++] = '\n';
		s[j] = '\0';
		square[i++] = s;
	}
	square[i] = NULL;
	return (square);
}
