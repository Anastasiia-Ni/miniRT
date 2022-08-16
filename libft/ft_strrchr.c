/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:58:22 by anifanto          #+#    #+#             */
/*   Updated: 2021/10/03 14:43:33 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	sb;

	str = (char *)s + ft_strlen(s);
	sb = (char)c;
	while (str >= s)
	{
		if (*str == sb)
			return (str);
		str--;
	}
	return (NULL);
}
