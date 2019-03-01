/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 02:15:41 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/01 01:27:21 by jcreux           ###   ########.fr       */
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
# define TR		"#..###"
# define HL		"#...##..#"
# define HR		"#..##...#"
# define S		"##.##"
# define Z		"##...##"
# define AL		"#..##..#"
# define AR		"#...##...#"
# define L		"#...#...##"
# define LR		"##..#...#"
# define J		"#...#..##"
# define JR		"##...#...#"
# define L2		"#...###"
# define L2R	"###.#"
# define J2		"#.###"
# define J2R	"###...#"

int		ft_read(int fd, char **line);
int		*count_tetri(char *s[]);
char	**array_maker(int fd);
int		valid_line(char *s, int line);

#endif
