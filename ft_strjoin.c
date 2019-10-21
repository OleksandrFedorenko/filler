/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:35:32 by afedoren          #+#    #+#             */
/*   Updated: 2017/11/13 13:35:33 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;

	if (!s1 || !s2)
		return (NULL);
	fresh = (ft_strnew(ft_strlen(s1) + ft_strlen(s2)));
	if (fresh == NULL)
		return (NULL);
	ft_strcat(fresh, s1);
	ft_strcat(fresh, s2);
	return (fresh);
}
