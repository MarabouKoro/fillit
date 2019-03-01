#include "read.c"
#include "valid_line.c"

#include <fcntl.h>
#include <stdio.h>

int		main(void)
{
	int		fd = open("valid_tetri.txt", O_RDONLY);
	char	*line;
	int		ret;
	int		nb_line = 0;

	while ((ret = ft_read(fd, &line)) > 0)
	{
		printf("%d - %s", valid_line(line, nb_line), line);
		nb_line++;
		if (nb_line == 5)
			nb_line = 0;
		free(line);
	}
	close(fd);
	return (0);
}
