/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrouchy <hrouchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:34:21 by hrouchy           #+#    #+#             */
/*   Updated: 2025/06/13 15:33:20 by hrouchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <limits.h>

static int	ft_iswhite(char c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int				index;
	int				s;
	unsigned int	r;

	index = 0;
	s = 1;
	r = 0;
	while (ft_iswhite(nptr[index]))
		index++;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
			s = -1;
		index++;
	}
	if (!(nptr[index] >= '0' && nptr[index] <= '9'))
		return (0);
	while (nptr[index] >= '0' && nptr[index] <= '9')
		r = r * 10 + (nptr[index++] - '0');
	if ((r > INT_MAX && s == 1) || (r > (unsigned)INT_MIN && s == -1))
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	return (s * r);
}
