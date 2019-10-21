/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:17:52 by afedoren          #+#    #+#             */
/*   Updated: 2018/09/22 13:17:54 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	all_about_piece(t_struct *list)
{
	size_piece(list);
	malloc_piece(list);
	fill_piece(list);
}

void	size_piece(t_struct *list)
{
	char	*line;
	int		i;

	line = NULL;
	i = 6;
	get_next_line(0, &line);
	while (ft_isdigit(line[i]) && line[i] != ' ')
	{
		list->p_size_y = list->p_size_y * 10 + line[i] - '0';
		i++;
	}
	i += 1;
	while (ft_isdigit(line[i]) || line[i] != ':')
	{
		list->p_size_x = list->p_size_x * 10 + line[i] - '0';
		i++;
	}
	ft_strdel(&line);
}

void	malloc_piece(t_struct *list)
{
	int i;

	i = -1;
	list->piece = (char**)ft_memalloc(sizeof(char *) * (list->p_size_y + 1));
	while (++i < list->p_size_y)
	{
		list->piece[i] = (char*)ft_memalloc(sizeof(char) * list->p_size_x + 1);
	}
	list->piece[i] = NULL;
}

void	fill_piece(t_struct *list)
{
	int		i;
	char	*line;

	line = NULL;
	i = -1;
	while (++i < list->p_size_y)
	{
		if (i == list->p_size_y)
			break ;
		else
			get_next_line(0, &line);
		ft_strcpy(list->piece[i], line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	list->piece[i] = NULL;
}
