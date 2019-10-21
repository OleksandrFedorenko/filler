/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:16:58 by afedoren          #+#    #+#             */
/*   Updated: 2018/09/22 13:17:03 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	find_opp(t_struct *list)
{
	int y;
	int x;

	y = 0;
	while (y < list->map_size_y)
	{
		x = 0;
		while (x < list->map_size_x)
		{
			if (list->map[y][x] == list->opp_p)
			{
				check_two(list, y, x);
			}
			x++;
		}
		y++;
	}
	dist_stars_opp(list);
}

void	dist_stars_opp(t_struct *list)
{
	list->enem_dist_tmp = 0;
	while ((list->final_y < list->map_size_y) && in_map(list))
	{
		while ((list->final_x < list->map_size_x) && in_map(list))
		{
			if (can_put(list))
			{
				dist_stars_opp_1(list);
			}
			list->final_x++;
		}
		list->final_y++;
	}
}

void	dist_stars_opp_1(t_struct *list)
{
	int dist_y;
	int dist_x;

	dist_y = -1;
	while (++dist_y < list->p_size_y)
	{
		dist_x = -1;
		while (++dist_x < list->p_size_x)
		{
			if (list->piece[dist_y][dist_x] == '*'
	&& list->map[list->final_y + dist_y][list->final_x + dist_x] == list->my_p)
			{
				check_one(list);
			}
			else if (list->piece[dist_y][dist_x] == '*'
	&& list->map[list->final_y + dist_y][list->final_x + dist_x] == list->opp_p)
			{
				return ;
			}
		}
	}
	distance(list);
}

void	distance(t_struct *list)
{
	if (list->enem_dist_tmp < list->tmp)
	{
		list->tmp = list->enem_dist_tmp;
		list->last_y = list->m_y;
		list->last_x = list->m_x;
	}
}
