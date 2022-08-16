/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:01:13 by anifanto          #+#    #+#             */
/*   Updated: 2022/06/28 13:15:17 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_pop_dot(char *str)
{
	int	i;

	i = ft_strchr(str, '.') - str;
	while (str[i])
	{
		str[i] = str[i + 1];
		i++;
	}
}

static double	ft_devide(int size)
{
	double	p;

	p = 1;
	while (size)
	{
		p *= 10;
		size--;
	}
	return (p);
}

double	ft_atod(const char *str)
{
	char	*tmp;
	int		dot;
	double	nb;

	if (!ft_strchr(str, '.'))
		return (ft_atoi(str));
	tmp = ft_strdup(str);
	if (!tmp)
		return (0.0l);
	dot = ft_strchr(str, '.') - str;
	ft_pop_dot(tmp);
	nb = ft_atoi(tmp);
	free(tmp);
	return (nb / ft_devide(ft_strlen(str) - 1 - dot));
}
