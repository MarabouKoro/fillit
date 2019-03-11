/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:03:09 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/11 16:59:23 by jcreux           ###   ########.fr       */
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

static char	*ft_ret(char *s, int n1, int n2)
{
	if (n1 == -1 || n2 == 1)
		error();
	if (s[0] != '\0')
		return (s);
	free(s);
	return (NULL);
}

static char	*ft_ret2(char *s1, char *s2)
{
	free(s1);
	return (s2);
}

static char	*tetri_maker(int fd)
{
	t_struct	st;
	static int	nb_line = 0;
	static int	test = 0;

	st.j = 0;
	st.str = ft_strnew(16);
	while ((st.ret = ft_read(fd, &st.line)) > 0)
	{
		test = 0;
		st.i = 0;
		if (valid_line(st.line, nb_line) == 1)
			error();
		if (st.line[0] == '\n' && (nb_line = 0) == 0)
		{
			test = 1;
			return (ft_ret2(st.line, st.str));
		}
		while (st.i < 4)
			st.str[st.j++] = st.line[st.i++];
		nb_line++;
		if (st.j == 16)
			st.str[st.j] = '\0';
		free(st.line);
	}
	return (ft_ret(st.str, st.ret, test));
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
