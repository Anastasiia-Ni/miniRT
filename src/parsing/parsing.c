/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:33:21 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/04 18:54:01 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/MiniRt.h"

int	extension_check(char *arg)
{
	int	i;

	i = ft_strlen(arg) - 3;
	if (ft_strncmp(".rt", (arg + i), 4) != 0)
		return (-1);
	return (0);
}

int	open_and_check(t_rt *rt, char *arg)
{
	int		fd;
	int		rd;
	char	*buf;

	fd = 0;
	rd = 0;
	buf = (char *) malloc(sizeof(char));
	if (!buf)
		error_exit(-1, ERR_MEM_AL, rt);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (-1);
	rd = read(fd, buf, 1);
	if (rd < 0)
	{
		free(buf);
		close (fd);
		return (-1);
	}
	close(fd);
	fd = open(arg, O_RDONLY);
	free(buf);
	return (fd);
}

int	parse(t_rt *rt, char *arg)
{
	int	fd;

	fd = 0;
	if (extension_check(arg) == -1)
		return (-1);
	fd = open_and_check(rt, arg);
	if (fd == -1)
		return (-1);
	if (parse_set_rt(rt, fd) == -1)
		return (-1);
	close (fd);
	return (0);
}
