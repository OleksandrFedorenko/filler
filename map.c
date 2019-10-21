/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:17:41 by afedoren          #+#    #+#             */
/*   Updated: 2018/09/22 13:17:43 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		all_about_map(t_struct *list)
{
	char	*line;

	line = NULL;
	if (list->map_size_x != 0 && list->map_size_y != 0)
	{
		get_next_line(0, &line);
		if (!line)
		{
			ft_strdel(&line);
			return (0);
		}
		if (ft_strstr(line, "Plateau"))
		{
			ft_strdel(&line);
			get_next_line(0, &line);
			ft_strdel(&line);
		}
		fill_map(list);
		ft_strdel(&line);
	}
	return (1);
}

void	size_map(t_struct *list)
{
	int		i;
	char	*line;

	line = NULL;
	i = 8;
	get_next_line(0, &line);
	if (ft_strstr(line, "Plateau"))
	{
		while (ft_isdigit(line[i]) && line[i] != ' ')
		{
			list->map_size_y = list->map_size_y * 10 + line[i] - '0';
			i++;
		}
		i++;
		while (ft_isdigit(line[i]) || line[i] != ':')
		{
			list->map_size_x = list->map_size_x * 10 + line[i] - '0';
			i++;
		}
	}
	ft_strdel(&line);
}

void	malloc_map(t_struct *list)
{
	int		i;

	i = -1;
	list->map = (char**)ft_memalloc(sizeof(char*) * (list->map_size_y + 1));
	while (++i < list->map_size_y)
	{
		list->map[i] = (char*)ft_memalloc(sizeof(char) * list->map_size_x + 1);
	}
}

void	fill_map(t_struct *list)
{
	int		i;
	char	*line;

	line = NULL;
	i = -1;
	while (++i < list->map_size_y)
	{
		if (i == list->map_size_y)
		{
			break ;
		}
		else
			get_next_line(0, &line);
		ft_strcpy(list->map[i], line + 4);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}
