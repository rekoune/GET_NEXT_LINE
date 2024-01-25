/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:19:17 by arekoune          #+#    #+#             */
/*   Updated: 2024/01/25 15:22:06 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_reture(char *line, char **reste)
{
	char	*reture;

	reture = malloc(ft_strlen(line, '\n') + 2);
	if (!reture)
		return (0);
	ft_strjoin(reture, line, 0, ft_strlen(line, '\n') + 1);
	*reste = malloc(ft_strlen(&line[check(line)], '\0') + 1);
	if (!(*reste))
		return (0);
	ft_strjoin(*reste, &line[check(line)], 0, ft_strlen(&line[check(line)],
			'\0'));
	return (reture);
}
