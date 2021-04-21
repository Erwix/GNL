/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:26:52 by egaliana          #+#    #+#             */
/*   Updated: 2021/02/04 16:22:54 by egaliana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char		*sbis;
	int			i;

	i = 0;
	if (!(sbis = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		sbis[i] = s[i];
		i++;
	}
	sbis[i] = '\0';
	return (sbis);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*s;
	int			len;
	int			i;
	int			j;

	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	i = -1;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(s = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[++i] != '\0')
		s[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		s[i + j] = s2[j];
	s[i + j] = '\0';
	free((char*)s1);
	return (s);
}
