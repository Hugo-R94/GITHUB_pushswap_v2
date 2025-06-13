/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrouchy <hrouchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 12:06:20 by hrouchy           #+#    #+#             */
/*   Updated: 2025/06/11 11:22:02 by hrouchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_free_split(char **str, int index)
{
	while (--index >= 0)
		free(str[index]);
	free(str);
}

static int	ft_count_words(char *str, char sep)
{
	int	index;
	int	count;

	count = 0;
	index = 0;
	while (str[index] == sep)
		index++;
	while (str[index])
	{
		if (str[index] != sep)
		{
			count++;
			while (str[index] && str[index] != sep)
				index++;
		}
		else
			while (str[index] && str[index] == sep)
				index++;
	}
	return (count);
}

static char	*allocate_word(char *str, char sep)
{
	int		size;
	char	*word;
	int		i;

	size = 0;
	while (str[size] && str[size] != sep)
		size++;
	word = malloc(size + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < size)
		word[i++] = *str++;
	word[i] = '\0';
	return (word);
}

static int	ft_splitcpy(char *str, int index, char sep, char **str_arr)
{
	while (*str)
	{
		while (*str && *str == sep)
			str++;
		if (*str)
		{
			str_arr[index] = allocate_word(str, sep);
			if (!str_arr[index])
			{
				ft_free_split(str_arr, index);
				return (0);
			}
			while (*str && *str != sep)
				str++;
			index++;
		}
	}
	str_arr[index] = NULL;
	return (1);
}

char	**ft_split(char *str, char c)
{
	char	**split_array;
	int		index;

	if (!str)
		return (NULL);
	index = 0;
	split_array = malloc((ft_count_words(str, c) + 1) * sizeof(char *));
	if (!split_array)
		return (NULL);
	if (!ft_splitcpy(str, index, c, split_array))
	{
		free(split_array);
		return (NULL);
	}
	return (split_array);
}
