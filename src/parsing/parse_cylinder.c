/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:30:19 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/04 18:54:39 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/MiniRt.h"

t_cylndr	*new_cylinder(t_rt *rt)
{
	t_cylndr	*ptr;

	ptr = (t_cylndr *) ft_calloc(sizeof(t_cylndr), 1);
	if (!ptr)
		error_exit(-1, ERR_MEM_AL, rt);
	ptr->next = NULL;
	return (ptr);
}

int	cylinder_errorcheck(t_rt *rt)
{
	if (rt->cylndr->coord.x < -MAX_SIZE || rt->cylndr->coord.x > MAX_SIZE || \
	rt->cylndr->coord.y < -MAX_SIZE || rt->cylndr->coord.y > MAX_SIZE || \
	rt->cylndr->coord.z < -MAX_SIZE || rt->cylndr->coord.z > MAX_SIZE)
		return (-1);
	if (rt->cylndr->orient.x < -1.0 || rt->cylndr->orient.x > 1.0 || \
	rt->cylndr->orient.y < -1.0 || rt->cylndr->orient.y > 1.0 || \
	rt->cylndr->orient.z < -1.0 || rt->cylndr->orient.z > 1.0)
		return (-1);
	if (rt->cylndr->color.x < 0 || rt->cylndr->color.x > 255 || \
	rt->cylndr->color.y < 0 || rt->cylndr->color.y > 255 || \
	rt->cylndr->color.z < 0 || rt->cylndr->color.z > 255)
		return (-1);
	if (rt->cylndr->radius < 0 || rt->cylndr->radius > 1000)
		return (-1);
	if (rt->cylndr->height < 0 || rt->cylndr->height > 1000)
		return (-1);
	if (rt->cylndr->reflect < 0 || rt->cylndr->reflect > 1 \
	|| rt->cylndr->specular < 0 || rt->cylndr->specular > 5000 \
	|| rt->cylndr->is_chess < -10 || rt->cylndr->is_chess > 10)
		return (-1);
	return (0);
}

void	set_cylinder_cont(char **line, t_rt *rt)
{
	rt->cylndr->color.x = ft_value(line[5], ',', 0, rt);
	rt->cylndr->color.y = ft_value(line[5], ',', 1, rt);
	rt->cylndr->color.z = ft_value(line[5], ',', 1, rt);
	if (array_size(line) >= 7)
		rt->cylndr->reflect = ft_value(line[6], ',', 0, rt);
	if (array_size(line) >= 8)
		rt->cylndr->specular = ft_value(line[7], ',', 0, rt);
	else
		rt->cylndr->specular = 2000;
	if (array_size(line) == 9)
		rt->cylndr->is_chess = ft_value(line[8], ',', 0, rt);
}

int	set_cylinder(char **line, t_rt *rt)
{
	if (comma_check(line[1]) == -1 || comma_check(line[2]) == -1 \
	|| comma_check(line[5]) == -1)
		return (-1);
	rt->cylndr->coord.x = ft_value(line[1], ',', 0, rt);
	rt->cylndr->coord.y = ft_value(line[1], ',', 1, rt);
	rt->cylndr->coord.z = ft_value(line[1], ',', 1, rt);
	rt->cylndr->orient.x = ft_value(line[2], ',', 0, rt);
	rt->cylndr->orient.y = ft_value(line[2], ',', 1, rt);
	rt->cylndr->orient.z = ft_value(line[2], ',', 1, rt);
	rt->cylndr->radius = ft_value(line[3], ',', 0, rt) / 2;
	rt->cylndr->height = ft_value(line[4], ',', 0, rt);
	set_cylinder_cont(line, rt);
	if (cylinder_errorcheck(rt) == -1)
		return (-1);
	normalize_vect(&rt->cylndr->orient);
	return (0);
}

int	parse_cylinder(char **line, t_rt *rt)
{
	int			size;
	t_cylndr	*temp;

	temp = rt->cylndr;
	while (rt->cylndr != NULL && rt->cylndr->next != NULL)
		rt->cylndr = rt->cylndr->next;
	if (rt->cylndr == NULL)
		rt->cylndr = new_cylinder(rt);
	else
	{
		rt->cylndr->next = new_cylinder(rt);
		rt->cylndr = rt->cylndr->next;
	}
	size = array_size(line);
	if (size < 6 || size > 9)
		return (-1);
	if (alpha_check(line) == -1)
		return (-1);
	if (set_cylinder(line, rt) == -1)
		return (-1);
	if (temp != NULL)
		rt->cylndr = temp;
	return (0);
}
