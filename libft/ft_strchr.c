/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 21:11:56 by anifanto          #+#    #+#             */
/*   Updated: 2021/09/28 15:09:35 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;
	char	smb;

	p = (char *)s;
	smb = (char)c;
	while (*p && *p != smb)
		p++;
	if (*p == smb)
		return (p);
	return (0);
}
