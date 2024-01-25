/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:16:35 by arekoune          #+#    #+#             */
/*   Updated: 2024/01/25 11:35:09 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*get_reture(char *line, char **reste);
int		check(char *str);
int		ft_strlen(char *str, char c);
char	*ft_strjoin(char *dest, char *src, int index, int size);
char	*ft_malloc(char *line, char *bufer);
char	*ft_strdup(char *str);

#endif
