#include "fillit.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "init_square.c"
#include "array_maker.c"
#include "check_array.c"
#include "valid_line.c"
#include "read.c"
#include "put_array_tetri.c"
#include "len_square.c"

int		main(int ac, char **av)
{
	int		i = 0;
	int		fd = open(av[1], O_RDONLY);
	char	**tab = init_square();
	char	**tab2 = check_array(array_maker(fd));

	if (ac != 2)
		return (1);
	tab = put_array_tetri(tab, tab2);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	printf("%d\n", len_square(tab, 1));
	close(fd);
	return (0);
}
