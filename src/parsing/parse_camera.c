/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:30:11 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/04 17:28:10 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/MiniRt.h"

int	set_camera(char **line, t_rt *rt)
{
	if (comma_check(line[1]) == -1)
		return (-1);
	rt->camera.coord.x = ft_value(line[1], ',', 0, rt);
	rt->camera.coord.y = ft_value(line[1], ',', 1, rt);
	rt->camera.coord.z = ft_value(line[1], ',', 1, rt);
	rt->camera.orient.x = ft_value(line[2], ',', 0, rt);
	rt->camera.orient.y = ft_value(line[2], ',', 1, rt);
	rt->camera.orient.z = ft_value(line[2], ',', 1, rt);
	rt->camera.fov = ft_value(line[3], ',', 0, rt);
	if (rt->camera.coord.x < -MAX_SIZE || rt->camera.coord.x > MAX_SIZE || \
	rt->camera.coord.y < -MAX_SIZE || rt->camera.coord.y > MAX_SIZE || \
	rt->camera.coord.z < -MAX_SIZE || rt->camera.coord.z > MAX_SIZE)
		return (-1);
	if (rt->camera.orient.x < -1.0 || rt->camera.orient.x > 1.0 || \
	rt->camera.orient.y < -1.0 || rt->camera.orient.y > 1.0 \
	|| rt->camera.orient.z < -1.0 || rt->camera.orient.z > 1.0)
		return (-1);
	if (rt->camera.fov < 0 || rt->camera.fov > 180)
		return (-1);
	normalize_vect(&rt->camera.orient);
	return (0);
}

int	parse_camera(char **line, t_rt *rt, t_parsecheck *min_check)
{
	int			size;
	static int	c;

	c++;
	min_check->camera = 1;
	if (c > 1)
		return (-1);
	size = array_size(line);
	if (size != 4)
		return (-1);
	if (alpha_check(line) == -1)
		return (-1);
	if (set_camera(line, rt) == -1)
		return (-1);
	return (0);
}
