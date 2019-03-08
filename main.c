/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:30:57 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/09 00:12:21 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		pos;
	int		line;
	int		fd;
	char	**tab;
	char	**square;

	pos = 0;
	line = 0;
	fd = open(av[1], O_RDONLY);
	if (ac != 2)
	{
		usage(av[0]);
		return (1);
	}
	tab = check_array(array_maker(fd));
	square = final_square(init_square(tab), tab);
	while (square[line])
	{
		while (square[line][pos])
			write(1, &square[line][pos++], 1);
		pos = 0;
		line++;
	}
	close(fd);
	return (0);
}
