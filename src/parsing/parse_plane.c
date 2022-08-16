/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:31:53 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/04 18:53:12 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/MiniRt.h"

t_plane	*new_plane(t_rt *rt)
{
	t_plane	*ptr;

	ptr = (t_plane *) ft_calloc(sizeof(t_plane), 1);
	if (!ptr)
		error_exit(-1, ERR_MEM_AL, rt);
	ptr->next = NULL;
	return (ptr);
}

int	plane_errorcheck(t_rt *rt)
{
	if (rt->plane->coord.x < -MAX_SIZE || rt->plane->coord.x > MAX_SIZE || \
	rt->plane->coord.y < -MAX_SIZE || rt->plane->coord.y > MAX_SIZE || \
	rt->plane->coord.z < -MAX_SIZE || rt->plane->coord.z > MAX_SIZE)
		return (-1);
	if (rt->plane->orient.x < -1.0 || rt->plane->orient.x > 1.0 || \
	rt->plane->orient.y < -1.0 || rt->plane->orient.y > 1.0 || \
	rt->plane->orient.z < -1.0 || rt->plane->orient.z > 1.0)
		return (-1);
	if (rt->plane->color.x < 0 || rt->plane->color.x > 255 || \
	rt->plane->color.y < 0 || rt->plane->color.y > 255 || \
	rt->plane->color.z < 0 || rt->plane->color.z > 255)
		return (-1);
	if (rt->plane->reflect < 0 || rt->plane->reflect > 1 || \
	rt->plane->specular < 0 || rt->plane->specular > 5000 || \
	rt->plane->is_chess < -10 || rt->plane->is_chess > 10)
		return (-1);
	return (0);
}

int	set_plane(char **line, t_rt *rt)
{
	if (comma_check(line[1]) == -1 || comma_check(line[2]) == -1 \
		|| comma_check(line[2]) == -1)
		return (-1);
	rt->plane->coord.x = ft_value(line[1], ',', 0, rt);
	rt->plane->coord.y = ft_value(line[1], ',', 1, rt);
	rt->plane->coord.z = ft_value(line[1], ',', 1, rt);
	rt->plane->orient.x = ft_value(line[2], ',', 0, rt);
	rt->plane->orient.y = ft_value(line[2], ',', 1, rt);
	rt->plane->orient.z = ft_value(line[2], ',', 1, rt);
	rt->plane->color.x = ft_value(line[3], ',', 0, rt);
	rt->plane->color.y = ft_value(line[3], ',', 1, rt);
	rt->plane->color.z = ft_value(line[3], ',', 1, rt);
	if (array_size(line) >= 5)
		rt->plane->reflect = ft_value(line[4], ',', 0, rt);
	if (array_size(line) >= 6)
		rt->plane->specular = ft_value(line[5], ',', 0, rt);
	else
		rt->plane->specular = 10;
	if (array_size(line) == 7)
		rt->plane->is_chess = ft_value(line[6], ',', 0, rt);
	if (plane_errorcheck(rt) == -1)
		return (-1);
	normalize_vect(&rt->plane->orient);
	return (0);
}

int	parse_plane(char **line, t_rt *rt)
{
	int		size;
	t_plane	*temp;

	temp = rt->plane;
	while (rt->plane != NULL && rt->plane->next != NULL)
		rt->plane = rt->plane->next;
	if (rt->plane == NULL)
		rt->plane = new_plane(rt);
	else
	{
		rt->plane->next = new_plane(rt);
		rt->plane = rt->plane->next;
	}
	size = array_size(line);
	if (size < 4 || size > 7)
		return (-1);
	if (alpha_check(line) == -1)
		return (-1);
	if (set_plane(line, rt) == -1)
		return (-1);
	if (temp != NULL)
		rt->plane = temp;
	return (0);
}
