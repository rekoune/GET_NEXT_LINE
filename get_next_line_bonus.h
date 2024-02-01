/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:33:42 by arekoune          #+#    #+#             */
/*   Updated: 2024/02/01 10:49:01 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		ft_read(char **line, int fd);
char	*join_reste(char *line, char *reste);
char	*reture_line(char *line, char **reture);
int		check_line(char *str);
char	*str_join(char *s1, char *s2);
int		str_len(char *str);
int		clean(char **str);

#endif