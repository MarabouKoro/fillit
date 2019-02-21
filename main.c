#include <stdio.h>
#include "libft/libft.h"
#include "fillit.h"

//#include "file_checker.c"
#include "counter_tetri.c"

int		main(void)
{
	// "....\n."
/*
	char	*s1 = "##..\n";
	char	*s2 = "##..\n";
	char	*s3 = "....\n";
	char	*s4 = ".#..\n";
	char	*s5 = "\n";
	
	printf("%d -- %s\n", valid_line(s1), s1);
	printf("%d -- %s\n", valid_line(s2), s2);
	printf("%d -- %s\n", valid_line(s3), s3);
	printf("%d -- %s\n", valid_line(s4), s4);
	printf("%d -- %s\n", valid_line(s5), s5);	// nb_line = 4 && nb_diese = 4
*/
	char	*test = "#...###........";

	printf("%d\n", count_tetri(test));
	return (0);
}
