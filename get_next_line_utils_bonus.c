/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:00:58 by arekoune          #+#    #+#             */
/*   Updated: 2024/02/01 11:11:11 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*mini_join(char *s1, char *s2, char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1 != 0)
		while (s1[i])
			(*str)[j++] = s1[i++];
	i = 0;
	if (s2 != 0)
		while (s2[i])
			(*str)[j++] = s2[i++];
	(*str)[j] = 0;
	free(s1);
	free(s2);
	return (*str);
}

char	*str_join(char *s1, char *s2)
{
	char	*str;
	int		len;
	int		total;

	if (!s1 && !s2)
		return (NULL);
	len = str_len(s1);
	total = len + str_len(s2);
	str = malloc(total + 1);
	if (!str)
	{
		free(s1);
		s1 = NULL;
		free(s2);
		s2 = NULL;
		return (NULL);
	}
	return (mini_join(s1, s2, &str));
}

int	clean(char **str)
{
	free(*str);
	*str = 0;
	return (0);
}
