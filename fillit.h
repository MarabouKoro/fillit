/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 02:15:41 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/06 09:50:22 by jcreux           ###   ########.fr       */
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

int		ft_read(int fd, char **line);
int		valid_line(char *s, int line);
char	**array_maker(int fd);
char	**check_array(char **array);
char	**init_square(void);
char	**put_array_tetri(char **square, char **array_tetri);
int		len_square(char **square, int nb_tetri);

#endif
