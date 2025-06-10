/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrouchy <hrouchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:06:52 by hrouchy           #+#    #+#             */
/*   Updated: 2025/06/10 17:02:33 by hrouchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "push_swap.h"
# include "checker.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
char	*ft_read(int fd, char *static_str);
char	*ft_line(char *statict_str);

void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(const char *str);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strjoin(const char *s1, const char *s2);

char	*ft_strchr(const char *s, int c);
char	*ft_next(char *buffer);
char	*ft_free(char *buffer, char *buf);
char	*ft_clean(char *static_str);
char	*ft_strdup(const char *s);

#endif
