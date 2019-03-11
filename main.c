/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:30:57 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/11 16:46:20 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "fillit.h"

static void	usage(char *str)
{
	write(1, "usage: ", 7);
	write(1, str, ft_strlen(str));
	write(1, " file\n", 6);
}

int			main(int ac, char **av)
{
	t_struct2	st;
	char		**tab;
	char		**square;

	st.line = 0;
	st.fd = open(av[1], O_RDONLY);
	if (ac != 2)
	{
		usage(av[0]);
		return (1);
	}
	tab = check_array(array_maker(st.fd));
	square = final_square(init_square(tab), tab);
	free(tab);
	while (square[st.line])
	{
		st.pos = 0;
		while (square[st.line][st.pos])
			write(1, &square[st.line][st.pos++], 1);
		free(square[st.line]);
		st.line++;
	}
	free(square);
	close(st.fd);
	return (0);
}
