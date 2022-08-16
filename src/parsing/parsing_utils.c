/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:33:07 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/04 16:33:19 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/MiniRt.h"

int	array_size(char **line)
{
	int	i;

	i = 0;
	while (line[i] != NULL && line[i][0] != '\n')
		i++;
	return (i);
}

double	ft_value(char *str, char delimeter, int reset, t_rt *rt)
{
	int			k;
	static int	i;
	char		*sub;
	double		value;

	if (reset == 0)
		i = 0;
	if (str[i] == delimeter || str[i] == ',')
		i = i + 1;
	k = i;
	while (str[i] != '\0' && str[i] != delimeter && str[i] != '\n')
		i = i + 1;
	sub = ft_substr(str, k, i - k);
	value = rt_atod(sub, rt);
	free (sub);
	return (value);
}

int	comma_helper(char *str, int *i)
{
	while (str != NULL && str[*i] != ',' && str[*i] != '\0' && str[*i] != '\n')
	{
		if (ft_isdigit(str[*i]) != 1 && str[*i] != '.' \
		&& str[*i] != '-' && str[*i] != '+')
			return (-1);
		*i = *i + 1;
	}
	if (str[*i] != ',' && str[*i] != '\0' && str[*i] != '\n')
		return (-1);
	if (str[*i] != '\0' && str[*i + 1] != '+' && str[*i + 1] != '-' && \
		ft_isdigit(str[*i + 1]) != 1 && str[*i] != '\n')
		return (-1);
	return (0);
}

int	comma_check(char *str)
{
	int	i;

	i = 0;
	if (comma_helper(str, &i) == -1)
		return (-1);
	i++;
	if (comma_helper(str, &i) == -1)
		return (-1);
	i++;
	if (comma_helper(str, &i) == -1)
		return (-1);
	return (0);
}

int	alpha_check(char **line)
{
	int	i;
	int	k;

	i = 1;
	while (line[i] != NULL)
	{
		k = 0;
		while (line[i][k] != '\0')
		{
			if ((ft_isdigit(line[i][k]) != 1) && line[i][k] != '.' \
					&& line[i][k] != '+' && line[i][k] != '-' \
					&& line[i][k] != ',' && line[i][k] != '\n')
				return (-1);
			k++;
		}
		i++;
	}
	return (0);
}
