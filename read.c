/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 01:51:23 by jcreux            #+#    #+#             */
/*   Updated: 2019/02/22 06:39:28 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"

char	*ft_free_strjoin(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
}

int			ft_read(int fd, char **line)
{
	int		n;
	char	buffer[BUFF_SIZE];
	char	*tmp;
	static int	a = 0;

	if (a == 1)
		return (0);
	if (fd < 0 || line == NULL)
		return (-1);
	tmp = ft_memalloc(1);
	while ((n = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (buffer[0] == '\n')
		{
			*line = ft_free_strjoin(tmp, buffer);
			tmp = NULL;
			return (1);
		}
		tmp = ft_free_strjoin(tmp, buffer);
	}
	if (n == 0 && tmp != NULL && a != 1)
	{
		*line = tmp;
		a = 1;
		return (1);
	}
	free(tmp);
	if (n == -1)
		return (-1);
	return (0);
}
