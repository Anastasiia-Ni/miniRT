/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:32:47 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/04 18:54:25 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/MiniRt.h"

t_sphere	*new_sphere(t_rt *rt)
{
	t_sphere	*ptr;

	ptr = (t_sphere *) ft_calloc(sizeof(t_sphere), 1);
	if (!ptr)
		error_exit(-1, ERR_MEM_AL, rt);
	ptr->next = NULL;
	return (ptr);
}

int	sphere_errorcheck(t_rt *rt)
{
	if (rt->sphere->color.x < 0 || rt->sphere->color.x > 255 || \
	rt->sphere->color.y < 0 || rt->sphere->color.y > 255 || \
	rt->sphere->color.z < 0 || rt->sphere->color.z > 255)
		return (-1);
	if (rt->sphere->coord.x < -MAX_SIZE || rt->sphere->coord.x > MAX_SIZE || \
	rt->sphere->coord.y < -MAX_SIZE || rt->sphere->coord.y > MAX_SIZE || \
	rt->sphere->coord.z < -MAX_SIZE || rt->sphere->coord.z > MAX_SIZE)
		return (-1);
	if (rt->sphere->radius < 0 || rt->sphere->radius > MAX_SIZE / 2)
		return (-1);
	if (rt->sphere->reflect < 0 || rt->sphere->reflect > 1 || \
	rt->sphere->specular < 0 || rt->sphere->specular > 5000 \
	|| rt->sphere->is_chess < -10 || rt->sphere->is_chess > 10)
		return (-1);
	return (0);
}

int	set_sphere(char **line, t_rt *rt)
{
	if (comma_check(line[1]) == -1 || comma_check(line[3]) == -1)
		return (-1);
	rt->sphere->coord.x = ft_value(line[1], ',', 0, rt);
	rt->sphere->coord.y = ft_value(line[1], ',', 1, rt);
	rt->sphere->coord.z = ft_value(line[1], ',', 1, rt);
	rt->sphere->radius = ft_value(line[2], ',', 0, rt) / 2;
	rt->sphere->color.x = ft_value(line[3], ',', 0, rt);
	rt->sphere->color.y = ft_value(line[3], ',', 1, rt);
	rt->sphere->color.z = ft_value(line[3], ',', 1, rt);
	if (array_size(line) >= 5)
		rt->sphere->reflect = ft_value(line[4], ',', 0, rt);
	if (array_size(line) >= 6)
		rt->sphere->specular = ft_value(line[5], ',', 0, rt);
	else
		rt->sphere->specular = 2000;
	if (array_size(line) == 7)
		rt->sphere->is_chess = ft_value(line[6], ',', 0, rt);
	if (sphere_errorcheck(rt) == -1)
		return (-1);
	return (0);
}

int	parse_sphere(char **line, t_rt *rt)
{
	int			size;
	t_sphere	*temp;

	temp = rt->sphere;
	while (rt->sphere != NULL && rt->sphere->next != NULL)
		rt->sphere = rt->sphere->next;
	if (rt->sphere == NULL)
		rt->sphere = new_sphere(rt);
	else
	{
		rt->sphere->next = new_sphere(rt);
		rt->sphere = rt->sphere->next;
	}
	size = array_size(line);
	if (size < 4 || size > 7)
		return (-1);
	if (alpha_check(line) == -1)
		return (-1);
	if (set_sphere(line, rt) == -1)
		return (-1);
	if (temp != NULL)
		rt->sphere = temp;
	return (0);
}
