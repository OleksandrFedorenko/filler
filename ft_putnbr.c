/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afedoren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:05:51 by afedoren          #+#    #+#             */
/*   Updated: 2017/11/09 15:05:52 by afedoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_putnbr(int n)
{
	long int number;

	number = n;
	if (number < 0)
	{
		ft_putchar('-');
		number = -number;
	}
	if (number > 9)
	{
		ft_putnbr(number / 10);
		ft_putnbr(number % 10);
	}
	else
		ft_putchar(number + '0');
}
