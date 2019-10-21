/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:09:39 by afedoren          #+#    #+#             */
/*   Updated: 2017/11/11 15:09:41 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*ft_strnew(size_t size)
{
	char *mem;

	if (!(mem = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_memset(mem, '\0', size + 1);
	return (mem);
}
