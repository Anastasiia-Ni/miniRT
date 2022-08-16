/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:35:47 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/04 17:24:58 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_read(char *ost, int fd, int len)
{
	if (fd != 0 && fd < 3)
		return (0);
	else if (fd > 255)
		return (0);
	else if (len > BUFFER_SIZE)
		return (0);
	else if ((ost == NULL || *ost == '\0') && len <= 0)
		return (0);
	return (1);
}

char	*join_end(char **ost)
{
	char	*line;

	line = gl_strdup(*ost);
	free (*ost);
	*ost = NULL;
	return (line);
}

char	*check_ost(char **ost)
{
	char	*line;
	int		i;
	char	*line1;

	i = 0;
	while ((*ost)[i] != '\n' && (*ost)[i] != '\0')
		i++;
	if ((*ost)[i] == '\0')
		line = join_end(&(*ost));
	else
	{
		line = gl_addost(*ost, i + 1);
		line1 = gl_strdup(&((*ost)[i + 1]));
		free (*ost);
		*ost = line1;
		if (**ost == '\0')
		{
			free(*ost);
			*ost = NULL;
		}
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*ost;
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int			len;

	len = read(fd, buf, BUFFER_SIZE);
	if (!check_read(ost, fd, len))
		return (NULL);
	while (len > 0)
	{
		buf[len] = '\0';
		if (ost)
		{
			line = gl_strjoin(ost, buf);
			free(ost);
			ost = line;
		}
		else
			ost = gl_strdup(buf);
		if (gl_strchr(buf, '\n'))
			break ;
		len = read(fd, buf, BUFFER_SIZE);
	}
	line = check_ost(&ost);
	return (line);
}
