/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_paraboloid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:31:07 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/04 18:53:29 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/MiniRt.h"

t_parab	*new_paraboloid(t_rt *rt)
{
	t_parab	*ptr;

	ptr = (t_parab *) ft_calloc(sizeof(t_parab), 1);
	if (!ptr)
		error_exit(-1, ERR_MEM_AL, rt);
	ptr->next = NULL;
	return (ptr);
}

int	parab_errorcheck(t_rt *rt)
{
	if (rt->parab->extremum.x < -MAX_SIZE || rt->parab->extremum.x > MAX_SIZE \
	|| rt->parab->extremum.y < -MAX_SIZE || rt->parab->extremum.y > MAX_SIZE \
	|| rt->parab->extremum.z < -MAX_SIZE || rt->parab->extremum.z > MAX_SIZE)
		return (-1);
	if (rt->parab->orient.x < -1.0 || rt->parab->orient.x > 1.0 || \
	rt->parab->orient.y < -1.0 || rt->parab->orient.y > 1.0 || \
	rt->parab->orient.z < -1.0 || rt->parab->orient.z > 1.0)
		return (-1);
	if (rt->parab->color.x < 0 || rt->parab->color.x > 255 || \
	rt->parab->color.y < 0 || rt->parab->color.y > 255 || \
	rt->parab->color.z < 0 || rt->parab->color.z > 255)
		return (-1);
	if (rt->parab->height < 0 || rt->parab->height > MAX_SIZE)
		return (-1);
	if (rt->parab->reflect < 0 || rt->parab->reflect > 1 || \
	rt->parab->specular < 0 || rt->parab->specular > 5000 || \
	rt->parab->is_chess < -10 || rt->parab->is_chess > 10)
		return (-1);
	return (0);
}

int	set_paraboloid(char **line, t_rt *rt)
{
	if (comma_check(line[1]) == -1 || comma_check(line[2]) == -1 || \
		comma_check(line[4]) == -1)
		return (-1);
	rt->parab->extremum.x = ft_value(line[1], ',', 0, rt);
	rt->parab->extremum.y = ft_value(line[1], ',', 1, rt);
	rt->parab->extremum.z = ft_value(line[1], ',', 1, rt);
	rt->parab->orient.x = ft_value(line[2], ',', 0, rt);
	rt->parab->orient.y = ft_value(line[2], ',', 1, rt);
	rt->parab->orient.z = ft_value(line[2], ',', 1, rt);
	rt->parab->height = ft_value(line[3], ',', 0, rt);
	rt->parab->color.x = ft_value(line[4], ',', 0, rt);
	rt->parab->color.y = ft_value(line[4], ',', 1, rt);
	rt->parab->color.z = ft_value(line[4], ',', 1, rt);
	if (array_size(line) >= 6)
		rt->parab->reflect = ft_value(line[5], ',', 0, rt);
	if (array_size(line) >= 7)
		rt->parab->specular = ft_value(line[6], ',', 0, rt);
	else
		rt->parab->specular = 2000;
	if (array_size(line) == 8)
		rt->parab->is_chess = ft_value(line[7], ',', 0, rt);
	if (parab_errorcheck(rt) == -1)
		return (-1);
	normalize_vect(&rt->parab->orient);
	return (0);
}

int	parse_paraboloid(char **line, t_rt *rt)
{
	int			size;
	t_parab		*temp;

	temp = rt->parab;
	while (rt->parab != NULL && rt->parab->next != NULL)
		rt->parab = rt->parab->next;
	if (rt->parab == NULL)
		rt->parab = new_paraboloid(rt);
	else
	{
		rt->parab->next = new_paraboloid(rt);
		rt->parab = rt->parab->next;
	}
	size = array_size(line);
	if (size < 5 || size > 8)
		return (-1);
	if (alpha_check(line) == -1)
		return (-1);
	if (set_paraboloid(line, rt) == -1)
		return (-1);
	if (temp != NULL)
		rt->parab = temp;
	return (0);
}
