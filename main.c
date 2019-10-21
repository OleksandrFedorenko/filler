/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 12:41:34 by afedoren          #+#    #+#             */
/*   Updated: 2018/09/22 13:17:34 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_struct	*list;

	list = (t_struct*)ft_memalloc(sizeof(t_struct));
	what_player(list);
	size_map(list);
	malloc_map(list);
	while (1)
	{
		if (!all_about_map(list))
			break ;
		all_about_piece(list);
		main_loop(list);
		ft_putnbr(list->last_y);
		ft_putchar(' ');
		ft_putnbr(list->last_x);
		ft_putchar('\n');
		free_arr(list->piece, list->p_size_y);
		list->p_size_x = 0;
		list->p_size_y = 0;
		list->last_x = 0;
		list->last_y = 0;
	}
	return (0);
}

void	free_arr(char **arr, int size)
{
	int i;

	i = -1;
	while (++i < size)
		ft_strdel(&arr[i]);
	free(arr);
}

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*mem;

	mem = malloc(sizeof(char) * size);
	if (mem == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		mem[i++] = 0;
	return ((void *)mem);
}

void	what_player(t_struct *list)
{
	char	*line;
	int		fd;

	fd = 0;
	get_next_line(0, &line);
	if (!line)
	{
		ft_strdel(&line);
		return ;
	}
	if (ft_strstr(line, "p1"))
	{
		list->my_p = 'O';
		list->opp_p = 'X';
	}
	else if (ft_strstr(line, "p2"))
	{
		list->my_p = 'X';
		list->opp_p = 'O';
	}
	ft_strdel(&line);
}
