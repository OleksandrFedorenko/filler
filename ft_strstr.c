/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:59:42 by afedoren          #+#    #+#             */
/*   Updated: 2017/11/14 17:19:13 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char	*l;
	const char	*b;

	if (!*little)
		return ((char *)big);
	while (*big)
	{
		l = little;
		b = big;
		while (*l && *b && *l == *b)
		{
			b++;
			l++;
		}
		if (!*l)
			return ((char*)big);
		big++;
	}
	return (0);
}
