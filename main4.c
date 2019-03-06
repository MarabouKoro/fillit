#include "fillit.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	int		fd = open(av[1], O_RDONLY);
	int		i = 0;
	char	**tab = check_array(array_maker(fd));
	char	**square = init_square(tab);

	if (ac != 2)
		return (1);
	while (square[i])
	{
		printf("%s", square[i]);
		i++;
	}
	close(fd);
	return (0);
}
