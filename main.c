#include <stdio.h>
#include "libft/libft.h"
#include "fillit.h"
//#include "file_checker.c"
#include "count_tetri.c"

#include <fcntl.h>
#include <stdlib.h>
#include "read.c"

int		main(void)
{
// "....\n."

//	char	*s1 = "##..\n";
//	char	*s2 = "....\n";
//	char	*s3 = "....\n";
//	char	*s4 = ".##.\n";
//	char	*s5 = "\n";
	
//	printf("%d -- %s\n", valid_line(s1), s1);
//	printf("%d -- %s\n", valid_line(s2), s2);
//	printf("%d -- %s\n", valid_line(s3), s3);
//	printf("%d -- %s\n", valid_line(s4), s4);
//	printf("%d -- %s\n", valid_line(s5), s5);	// nb_line = 4 && nb_diese = 4

/*
	static char	*test[22] = {O, I, IR, T, TR, HL, HR, S, Z, AL, AR, L, LR, J, JR, L2, L2R, J2, J2R};
	int		*tab = count_tetri(test);
	int		i = 0;
	int		j = 21;

	while (i < 19)
		printf("%d -- %d\n", j++, tab[i++]);
	return (0);
*/

	int		fd = open("text.txt", O_RDONLY);
	char	*line;
	int		res;

	while ((res = ft_read(fd, &line)) > 0)
	{
		printf("%d -- %s", res, line);
		free(line);
	}
	printf("%d\n", res);

	close (fd);
	return (0);
}
