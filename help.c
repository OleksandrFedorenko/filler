/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 13:27:01 by afedoren          #+#    #+#             */
/*   Updated: 2018/09/22 13:27:05 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		yes(t_struct *list, int count, int y, int x)
{
	list->find_dist = count;
	list->find_x = x;
	list->find_y = y;
	return (1);
}

void	check_one(t_struct *list)
{
	list->enem_dist = 7777;
	list->enem_dist_tmp += (ft_abs(list->find_y - list->final_y)
	+ ft_abs(list->find_x - list->final_x));
}

int		check_two(t_struct *list, int y, int x)
{
	int count;

	count = 0;
	count = (ft_abs((list->final_y - y)) + ft_abs((list->final_x - x)));
	return (count < list->find_dist ? yes(list, count, y, x) : 0);
}
