#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include "libft/libft.h"
#include "fillit.h"

#include "check_array.c"
#include "array_maker.c"
#include "valid_line.c"
#include "read.c"

int		main(int ac, char **av)
{
	int		fd = open(av[1], O_RDONLY);
/*
	char	**tab = array_maker(fd);
	int		i = 0;

	if (ac != 2)
		return (1);
	while (tab[i])
	{
		printf("%d -- %s\n", i+1, tab[i]);
		i++;
	}
*/
	int		i = 0;
	int		line = 1;
	char	**tab = check_array(array_maker(fd));

	if (ac != 2)
		return (1);
	while (tab[i])
	{
		printf("%d -- %s\n", line, tab[i]);
		line++;
		i++;
	}

	close(fd);
	return (0);
}
