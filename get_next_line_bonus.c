/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arekoune <arekoune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 10:33:45 by arekoune          #+#    #+#             */
/*   Updated: 2024/02/15 19:14:20 by arekoune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_read(char **line, int fd)
{
	int		nf;
	int		num_read;
	char	*bufer;

	nf = 0;
	while (!nf)
	{
		bufer = malloc(BUFFER_SIZE + 1);
		if (!bufer)
		{
			free(*line);
			*line = NULL;
			return ;
		}
		num_read = read(fd, bufer, BUFFER_SIZE);
		bufer[num_read] = '\0';
		nf = check_line(bufer);
		*line = str_join(*line, bufer);
		if (!(*line))
			return ;
		if (num_read == 0)
			return ;
	}
}

char	*join_reste(char *line, char *reste)
{
	char	*str;
	int		len;
	int		i;

	if (!reste)
		return (0);
	i = 0;
	len = str_len(reste);
	str = malloc(len + 1);
	if (!str)
	{
		free(line);
		return (NULL);
	}
	len = 0;
	while (reste[len])
	{
		str[len] = reste[len];
		len++;
	}
	str[len] = 0;
	free(line);
	return (str);
}

char	*mini_reture_line(char *line, char **reture, int i)
{
	int	j;

	j = 0;
	*reture = malloc(i + 1);
	if (!(*reture))
		return (NULL);
	while (j < i)
	{
		(*reture)[j] = line[j];
		j++;
	}
	(*reture)[j] = 0;
	return (&(line[i]));
}

char	*reture_line(char *line, char **reture)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!line)
		return (*reture = NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
		return (mini_reture_line(line, reture, i));
	*reture = malloc(i + 2);
	if (!(*reture))
		return (NULL);
	while (j <= i)
	{
		(*reture)[j] = line[j];
		j++;
	}
	(*reture)[j] = 0;
	return (&(line[i + 1]));
}

char	*get_next_line(int fd)
{
	static char	*line[OPEN_MAX];
	char		*reture;
	char		*reste;

	if (fd < 0 || fd > OPEN_MAX)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
	{
		free(line[fd]);
		line[fd] = NULL;
		return (NULL);
	}
	ft_read(&line[fd], fd);
	reste = reture_line(line[fd], &reture);
	if (!reste || !line[fd][0])
	{
		free(line[fd]);
		line[fd] = NULL;
		free(reture);
		return (NULL);
	}
	line[fd] = join_reste(line[fd], reste);
	return (reture);
}
