#include "fillit.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "init_square.c"
#include "array_maker.c"
#include "check_array.c"
#include "valid_line.c"
#include "read.c"
#include "put_tetri.c"

int		main(int ac, char **av)
{
	int		i = 0;
	int		fd = open(av[1], O_RDONLY);
	char	**tab = check_array(array_maker(fd));
	char	**tab2 = init_square();
	char	**old_tab2 = tab2;
	int		line = 0;
	int		pos = 0;
	int		letter = 65;

	if (ac != 2)
		return (1);
	while (tab[i])
	{
		tab2 = put_tetri(tab2, tab[i], line, pos, letter);
		while (tab2 == NULL)
		{
			tab2 = old_tab2;
			pos++;
			tab2 = put_tetri(tab2, tab[i], line, pos, letter);
		}
		letter++;
		pos = 0;
		i++;
	}
	i = 0;
	while (tab2[i])
	{
		printf("%s\n", tab2[i]);
		i++;
	}
	close(fd);
	return (0);
}
