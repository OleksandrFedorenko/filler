/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:16:39 by afedoren          #+#    #+#             */
/*   Updated: 2018/09/22 13:16:46 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		in_map(t_struct *list)
{
	if ((list->m_y + list->p_size_y < list->map_size_y + 1)
	&& (list->m_x + list->p_size_x < list->map_size_x + 1))
		return (1);
	return (0);
}

void	main_loop(t_struct *list)
{
	list->tmp = 9999;
	list->find_dist = 77777;
	list->m_y = -1;
	while (++list->m_y < list->map_size_y)
	{
		list->m_x = -1;
		while (++list->m_x < list->map_size_x)
		{
			if (can_put(list))
			{
				list->final_y = list->m_y;
				list->final_x = list->m_x;
				find_opp(list);
				list->final_x = 0;
				list->final_y = 0;
			}
		}
	}
}

int		can_put(t_struct *list)
{
	int touch;

	touch = 0;
	list->p_y = -1;
	while (++list->p_y < list->p_size_y && in_map(list))
	{
		list->p_x = -1;
		while (++list->p_x < list->p_size_x && in_map(list))
		{
			if (list->piece[list->p_y][list->p_x] == '*'
	&& (list->map[list->m_y + list->p_y][list->m_x + list->p_x] == list->my_p ||
	list->map[list->m_y + list->p_y]
	[list->m_x + list->p_x] == tolower(list->my_p)))
				touch++;
			else if (list->piece[list->p_y][list->p_x] == '*'
	&& list->map[list->m_y + list->p_y][list->m_x + list->p_x] == list->opp_p)
			{
				return (0);
			}
		}
	}
	return ((touch) != 1 ? 0 : 1);
}
