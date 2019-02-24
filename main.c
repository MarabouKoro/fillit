#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "libft/libft.h"
#include "fillit.h"

#include "count_tetri.c"
#include "read.c"
#include "array_tetri.c"

int		main(int ac, char **av)
{
	int		fd = open(av[1], O_RDONLY);
/*
	char	**tab = array_maker(fd);
	int		i = 0;

	if (ac != 2)
		return (1);
	while (i < 7)
	{
		printf("%d -- %s\n", i+1, tab[i]);
		i++;
	}
*/
	int		i = 0;
	int		line = 21;
	int		*tab = count_tetri(array_maker(fd));

	if (ac != 2)
		return (1);
	while (i < 19)
	{
		printf("%d -- %d\n", line, tab[i]);
		line++;
		i++;
	}

	close(fd);
	return (0);
}
