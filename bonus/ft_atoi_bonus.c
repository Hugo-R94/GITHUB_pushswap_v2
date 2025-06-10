/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrouchy <hrouchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:34:21 by hrouchy           #+#    #+#             */
/*   Updated: 2025/06/10 16:26:17 by hrouchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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
	int				signe;
	unsigned int	result;

	index = 0;
	signe = 1;
	result = 0;
	while (ft_iswhite(nptr[index]))
		index++;
	if (nptr[index] == '-' || nptr[index] == '+')
	{
		if (nptr[index] == '-')
			signe = -1;
		index++;
	}
	if (!(nptr[index] >= '0' && nptr[index] <= '9'))
		return (0);
	while (nptr[index] >= '0' && nptr[index] <= '9')
		result = result * 10 + (nptr[index++] - '0');
	if ((result > INT_MAX && signe == 1) || (result > INT_MAX && signe == -1))
	{
		ft_putstr_fd("error\n", 2);
		exit(EXIT_FAILURE);
	}
	return (signe * result);
}
