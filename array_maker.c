/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:03:09 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/09 15:57:48 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "fillit.h"

void		error(void)
{
	write(1, "error\n", 6);
	exit(1);
}

static char	*tetri_maker(int fd)
{
	t_struct	st;
	static int	nb_line = 0;

	st.j = 0;
	st.str = ft_strnew(16);
	while ((st.ret = ft_read(fd, &st.line)) > 0)
	{
		st.i = 0;
		if (valid_line(st.line, nb_line) == 1)
			error();
		if (st.line[0] == '\n' && (nb_line = 0) == 0)
			return (st.str);
		while (st.i < 4)
			st.str[st.j++] = st.line[st.i++];
		nb_line++;
		if (st.j == 16)
			st.str[st.j] = '\0';
	}
	if (st.ret == -1 || st.line[0] == '\n')
		error();
	if (st.str[0] != '\0')
		return (st.str);
	return (NULL);
}

char		**array_maker(int fd)
{
	int		i;
	char	*str;
	char	**tab;

	i = 0;
	tab = ft_memalloc(27);
	str = tetri_maker(fd);
	while (str != NULL)
	{
		tab[i] = str;
		str = tetri_maker(fd);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
