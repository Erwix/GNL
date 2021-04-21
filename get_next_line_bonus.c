/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 12:35:27 by egaliana          #+#    #+#             */
/*   Updated: 2021/04/21 16:52:08 by egaliana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		check_bn(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next(char *s)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	if (!(next = malloc(sizeof(char) * ((ft_strlen(s) - i) + 1))))
		return (NULL);
	while (s[i])
		next[j++] = s[i++];
	next[j] = '\0';
	free(s);
	return (next);
}

char	*get_line(char *s)
{
	int		i;
	char	*line;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	if (!(line = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	line[i] = '\0';
	while (--i >= 0)
		line[i] = s[i];
	return (line);
}

int		get_next_line(int fd, char **line)
{
	static char *s[4096];
	char		*buff;
	int			ret;

	ret = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!check_bn(s[fd]) && ret != 0)
	{
		if ((ret = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[ret] = '\0';
		s[fd] = ft_strjoin(s[fd], buff);
	}
	free(buff);
	*line = get_line(s[fd]);
	s[fd] = get_next(s[fd]);
	if (ret == 0)
		return (0);
	return (1);
}
