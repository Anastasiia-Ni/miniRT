/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 09:04:29 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/05 09:04:52 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/MiniRt.h"

void	free_plane_sphere(t_rt **ptr_rt)
{
	t_rt		*rt;
	t_plane		*plane;
	t_sphere	*sphere;

	rt = *ptr_rt;
	plane = NULL;
	sphere = NULL;
	while (rt->plane != NULL)
	{
		plane = rt->plane;
		rt->plane = rt->plane->next;
		free (plane);
	}
	while (rt->sphere != NULL)
	{
		sphere = rt->sphere;
		rt->sphere = rt->sphere->next;
		free (sphere);
	}
}

void	free_cyl_parab(t_rt **ptr_rt)
{
	t_rt		*rt;
	t_cylndr	*cylndr;
	t_parab		*parab;

	cylndr = NULL;
	parab = NULL;
	rt = *ptr_rt;
	while (rt->cylndr != NULL)
	{
		cylndr = rt->cylndr;
		rt->cylndr = rt->cylndr->next;
		free (cylndr);
	}
	while (rt->parab != NULL)
	{
		parab = rt->parab;
		rt->parab = rt->parab->next;
		free (parab);
	}
}
