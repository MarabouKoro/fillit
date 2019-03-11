/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 02:15:41 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/11 16:44:32 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

/*
** definition des patterns de tetriminos
*/
# define O		"##..##"
# define I		"#...#...#...#"
# define IR		"####"
# define T		"###..#"
# define TR		".#..###"
# define HL		"#...##..#"
# define HR		".#..##...#"
# define S		".##.##"
# define Z		"##...##"
# define AL		".#..##..#"
# define AR		"#...##...#"
# define L		"#...#...##"
# define LR		"##..#...#"
# define J		".#...#..##"
# define JR		"##...#...#"
# define L2		"#...###"
# define L2R	"###.#"
# define J2		"..#.###"
# define J2R	"###...#"

/*
** declaration des structures
*/
typedef struct	s_list
{
	char	*line;
	char	*str;
	int		i;
	int		j;
	int		ret;
}				t_struct;

typedef struct	s_list2
{
	int		i;
	int		init_size;
	int		pos;
	int		line;
	int		fd;
}				t_struct2;

/*
** prototypes des fonctions
*/
int				ft_read(int fd, char **line);
int				valid_line(char *s, int line);
char			**array_maker(int fd);
char			**check_array(char **array);
char			**init_square(char **array_tetri);
int				len_square(int nb_tetri);
int				len_tetri(char *tetri);
int				width_tetri(char *tetri);
int				count_tetri(char **array_tetri);
int				find_pos(char **square, int letter);
int				find_line(char **square, int letter);
char			**final_square(char **square, char **array);
char			**new_square(int size);
void			error(void);
int				find_tetri(char *s);
int				cs(char **square, char *tetri, int line, int pos);

#endif
