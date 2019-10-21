/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 12:23:32 by afedoren          #+#    #+#             */
/*   Updated: 2018/03/04 12:23:40 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	ft_check_rest(char *rest, char **line)
{
	char			*pos;

	pos = ft_strchr(rest, '\n');
	if (!rest)
		return (0);
	while (pos)
	{
		*pos = '\0';
		*line = ft_strdup(rest);
		ft_strncpy(rest, &pos[1], ft_strlen(&pos[1]) + 1);
		return (1);
	}
	if (ft_strlen(rest) > 0)
	{
		*line = ft_strdup(rest);
		*rest = '\0';
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	int				byte;
	char			*buff;
	static char		*rest;
	char			*tmp;

	!rest ? rest = ft_strnew(0) : 0;
	buff = ft_strnew(BUFF_SIZE + 1);
	while (!(ft_strchr(rest, '\n')) || !(ft_strchr(rest, '\0')))
	{
		if ((byte = read(fd, buff, BUFF_SIZE)) == -1)
			return (-1);
		if (byte == 0)
		{
			ft_strdel(&buff);
			return (ft_check_rest(rest, line));
		}
		buff[byte] = '\0';
		tmp = ft_strjoin(rest, buff);
		ft_strdel(&rest);
		rest = tmp;
	}
	ft_strdel(&buff);
	return (ft_check_rest(rest, line));
}
