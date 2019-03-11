/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 01:51:23 by jcreux            #+#    #+#             */
/*   Updated: 2019/03/11 17:12:54 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

static char	*free_strjoin(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
}

static int	ft_ret(char *s, char **line)
{
	*line = s;
	return (1);
}

int			ft_read(int fd, char **line)
{
	int			n;
	char		buffer[2];
	char		*tmp;
	static int	check = 0;

	if (fd < 0 || line == NULL || (tmp = ft_memalloc(1)) == NULL)
		return (-1);
	while ((n = read(fd, buffer, 1)) > 0)
	{
		check = 1;
		buffer[1] = '\0';
		if (buffer[0] == '\n')
			return (ft_ret(free_strjoin(tmp, buffer), line));
		tmp = free_strjoin(tmp, buffer);
	}
	if (n == -1)
		return (-1);
	if (check == 0)
		error();
	if (n == 0 && tmp[0] != '\0')
		return (ft_ret(tmp, line));
	free(tmp);
	return (0);
}
