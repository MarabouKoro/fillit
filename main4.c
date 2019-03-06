#include "fillit.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	int		fd = open(av[1], O_RDONLY);
	int		i = 0;
	char	**tab = check_array(array_maker(fd));
	int		len = len_square(count_tetri(tab));
	char	*square = init_square(tab);

	if (ac != 2)
		return (1);
	while (square[i])
	{
		if (i != 0 && i % len == 0)
			printf("\n");
		printf("%c", square[i]);
		i++;
	}
	printf("\n");

	close(fd);
	return (0);
}
