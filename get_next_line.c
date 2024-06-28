/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:30:21 by toferrei          #+#    #+#             */
/*   Updated: 2024/06/28 13:45:12 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_strlen_gnl(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (++i);
	return (i);
}

static void	ft_clean_buf(char *buf)
{
	int	i;
	int	l;
	int	j;

	i = ft_strlen_gnl(buf) - 1;
	j = 0;
	l = 0;
	while (buf[l])
		l++;
	buf[i++] = '\0';
	while (i < l)
		buf[j++] = buf[i++];
	buf[j] = '\0';
}

static char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*s_res;
	int		i;
	int		j;

	j = 0;
	i = 0;
	s_res = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!s_res)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			s_res[i] = s1[i];
			i++;
		}
	}
	while (i < ft_strlen_gnl(s1) + ft_strlen_gnl(s2))
		s_res[i++] = s2[j++];
	s_res[i] = '\0';
	if (s1)
		free(s1);
	ft_clean_buf(s2);
	return (s_res);
}

static int	chrnline(char *s)
{
	while (*s != '\0' && *s != '\n')
		s++;
	if (*s == '\n')
		return (1);
	else
		return (0);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*result;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	result = NULL;
	i = 1;
	while (i > 0)
	{
		if (!*buf)
		{
			i = read(fd, buf, BUFFER_SIZE);
			if (i == 0)
				return (result);
			if (i == -1)
				return (NULL);
			buf[i] = '\0';
		}
		result = ft_strjoin_gnl(result, buf);
		if (chrnline(result))
			break ;
	}
	return (result);
}
