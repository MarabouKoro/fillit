/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 01:51:23 by jcreux            #+#    #+#             */
/*   Updated: 2019/02/23 21:29:12 by jcreux           ###   ########.fr       */
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
	int			n;
	char		buffer[1];
	char		*tmp;

	if (fd < 0 || line == NULL)
		return (-1);
	tmp = ft_memalloc(1);
	while ((n = read(fd, buffer, 1)) > 0)
	{
		if (buffer[0] == '\n')
		{
			*line = ft_free_strjoin(tmp, buffer);
			return (1);
		}
		tmp = ft_free_strjoin(tmp, buffer);
	}
	if (n == 0 && tmp[0] != '\0')
	{
		*line = tmp;
		return (1);
	}
	free(tmp);
	if (n == -1)
		return (-1);
	return (0);
}
