/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 11:08:30 by afedoren          #+#    #+#             */
/*   Updated: 2018/09/28 11:08:36 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	char		*line;
	t_visual	*list;

	line = NULL;
	list = (t_visual*)malloc(sizeof(t_visual));
	list->o = 0;
	list->x = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (ft_strchr(line, '$'))
			ft_strchr(line, '1') ? printf(CYAN "%s\n" RESET, line)
		: printf(MAG "%s\n" RESET, line);
		if (ft_isdigit(line[0]))
			check_one_visual(line);
		else if (line[0] == '.' || line[0] == '*'
			|| line[0] == 'P')
			printf(SPEC "%s\n", line);
		if (ft_strstr(line, "== O"))
			check_score_o(line, list);
		else if (ft_strstr(line, "== X"))
			check_score_x(line, list);
		free(line);
	}
	make_winner(list);
	return (0);
}

void	check_one_visual(char *line)
{
	while (*line)
	{
		if (*line == 'X')
			printf(CYAN "%c" RESET, *line);
		else if (*line == 'O')
			printf(MAG "%c" RESET, *line);
		else
			printf(LIGHT "%c" RESET, *line);
		line++;
	}
	printf("\n");
}

void	check_score_o(char *line, t_visual *list)
{
	int i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	while (ft_isdigit(line[i]))
	{
		list->o = list->o * 10 + line[i] - '0';
		i++;
	}
	printf(MAG "SCORE FOR PLAYER 1(O)  %d\n", list->o);
}

void	check_score_x(char *line, t_visual *list)
{
	int i;

	i = 0;
	while (!ft_isdigit(line[i]))
		i++;
	while (ft_isdigit(line[i]))
	{
		list->x = list->x * 10 + line[i] - '0';
		i++;
	}
	printf(CYAN"SCORE FOR PLAYER 2(X)  %d\n", list->x);
}

void	make_winner(t_visual *list)
{
	if (list->x < list->o)
		printf(MAG "WINNER PLAYER 1 WITH SCORE %d\n", list->o);
	else if (list->o < list->x)
		printf(CYAN "WINNER PLAYER 2 WITH SCORE %d\n", list->x);
	else if (list->o == list->x)
		printf(SPEC "DRAW\n");
}
