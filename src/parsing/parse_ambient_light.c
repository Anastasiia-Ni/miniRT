/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ambient_light.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:29:58 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/04 17:28:06 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/MiniRt.h"

int	set_ambient(char **line, t_rt *rt)
{
	rt->ambient.ratio = rt_atod(line[1], rt);
	if (rt->ambient.ratio < 0.0 || rt->ambient.ratio > 1.0)
		return (-1);
	if (comma_check(line[2]) == -1)
		return (-1);
	rt->ambient.color.x = ft_value(line[2], ',', 0, rt);
	rt->ambient.color.y = ft_value(line[2], ',', 1, rt);
	rt->ambient.color.z = ft_value(line[2], ',', 1, rt);
	if (rt->ambient.color.x < 0 || rt->ambient.color.x > 255 || \
	rt->ambient.color.y < 0 || rt->ambient.color.y > 255 || \
	rt->ambient.color.z < 0 || rt->ambient.color.z > 255)
		return (-1);
	return (0);
}

int	parse_ambient(char **line, t_rt *rt, t_parsecheck *min_check)
{
	int			size;
	static int	a;

	a++;
	min_check->ambient = 1;
	if (a > 1)
		return (-1);
	size = array_size(line);
	if (size != 3)
		return (-1);
	if (alpha_check(line) == -1)
		return (-1);
	if (set_ambient(line, rt) == -1)
		return (-1);
	return (0);
}

int	set_light(char **line, t_rt *rt)
{
	if (comma_check(line[1]) == -1)
		return (-1);
	if (comma_check(line[3]) == -1)
		return (-1);
	rt->light.coord.x = ft_value(line[1], ',', 0, rt);
	rt->light.coord.y = ft_value(line[1], ',', 1, rt);
	rt->light.coord.z = ft_value(line[1], ',', 1, rt);
	rt->light.ratio = ft_value(line[2], ',', 0, rt);
	rt->light.color.x = ft_value(line[3], ',', 0, rt);
	rt->light.color.y = ft_value(line[3], ',', 1, rt);
	rt->light.color.z = ft_value(line[3], ',', 1, rt);
	if (rt->light.color.x < 0 || rt->light.color.x > 255 || \
	rt->light.color.y < 0 || rt->light.color.y > 255 || \
	rt->light.color.z < 0 || rt->light.color.z > 255)
		return (-1);
	if (rt->light.coord.x < -MAX_SIZE || rt->light.coord.x > MAX_SIZE || \
	rt->light.coord.y < -MAX_SIZE || rt->light.coord.y > MAX_SIZE || \
	rt->light.coord.z < -MAX_SIZE || rt->light.coord.z > MAX_SIZE)
		return (-1);
	if (rt->light.ratio < 0.0 || rt->light.ratio > 1.0)
		return (-1);
	return (0);
}

int	parse_light(char **line, t_rt *rt, t_parsecheck *min_check)
{
	int			size;
	static int	l;

	l++;
	min_check->light = 1;
	if (l > 1)
		return (-1);
	size = array_size(line);
	if (size != 4)
		return (-1);
	if (alpha_check(line) == -1)
		return (-1);
	if (set_light(line, rt) == -1)
		return (-1);
	return (0);
}
