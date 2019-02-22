/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcreux <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 01:51:23 by jcreux            #+#    #+#             */
/*   Updated: 2019/02/22 04:09:30 by jcreux           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"

int			ft_read(int fd, char **line)
{
	int		n;
	char	buffer[BUFF_SIZE];
	char	*tmp;

	tmp = ft_strnew(0);
	if (fd < 0 || line == NULL)
		return (-1);
	while ((n = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (buffer[0] == '\n')
		{
			*line = ft_strjoin(tmp, buffer);
			return (1);
		}
		tmp = ft_strjoin(tmp, buffer);
	}
	if (n == -1)
		return (-1);
	return (0);
}
