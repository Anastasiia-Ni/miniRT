/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 17:57:28 by anifanto          #+#    #+#             */
/*   Updated: 2021/10/03 14:44:24 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	sb;
	unsigned char	*str;

	sb = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == sb)
			return (str);
		str++;
	}
	return (NULL);
}
