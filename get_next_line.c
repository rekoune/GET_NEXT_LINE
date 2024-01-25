/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:15:53 by arekoune          #+#    #+#             */
/*   Updated: 2024/01/25 15:20:57 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

int	ft_strlen(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != c)
		i++;
	return (i);
}

char	*ft_strjoin(char *dest, char *src, int index, int size)
{
	int	i;

	i = 0;
	if (!(src) || !(dest))
		return (0);
	while (i < size)
		dest[index++] = src[i++];
	dest[index] = '\0';
	return (dest);
}

char	*ft_malloc(char *line, char *bufer)
{
	int		line_len;
	int		bufer_len;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line_len = ft_strlen(line, '\0');
	bufer_len = ft_strlen(bufer, '\0');
	str = malloc(line_len + bufer_len + 1);
	if (!str)
		return (0);
	if (line != 0)
	{
		while (line[i])
			str[i++] = line[j++];
	}
	str[i] = '\0';
	j = 0;
	if (bufer != 0)
	{
		while (bufer[j])
			str[i++] = bufer[j++];
	}
	str[i] = '\0';
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*reture;
	char		*bufer;
	static char	*reste;
	int			red;

	reture = 0;
	red = 0;
	bufer = malloc(BUFFER_SIZE + 1);
	if (!bufer)
		return (0);
	line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, bufer, 0) < 0)
	{
		free(reste);
		free(bufer);
		free(line);
		reste = 0;
		return (0);
	}
	if (check(reste) >= 0)
	{
		reture = get_reture(reste, &reste);
		free(bufer);
		return (reture);
	}
	while ((red = read(fd, bufer, BUFFER_SIZE)))
	{
		bufer[red] = '\0';
		line = ft_malloc(line, reste);
		line = ft_malloc(line, bufer);
		if (check(line) > 0)
		{
			reture = get_reture(line, &reste);
			free(line);
			break ;
		}
		reture = line;
	}
	free(bufer);
	if (red == 0 && reste && reste[0] && check(reste) < 0)
	{
		reture = reste;
		reste = 0;
	}
	return (reture);
}
