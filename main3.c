#include "fillit.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	int		i = 0;
	int		fd = open(av[1], O_RDONLY);
	char	**tab = check_array(array_maker(fd));
	char	**tab2 = put_array_tetri(init_square(), tab);

	if (ac != 2)
		return (1);
	while (tab2[i])
	{
		printf("%s\n", tab2[i]);
		i++;
	}
	printf("%d\n", len_square(tab2, 26));
	close(fd);
	return (0);
}
