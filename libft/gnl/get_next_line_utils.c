/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:36:24 by anifanto          #+#    #+#             */
/*   Updated: 2021/10/17 09:51:39 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gl_strlen(char *s)
{
	int	n;

	n = 0;
	while (*s != '\0')
	{
		n++;
		s++;
	}
	return (n);
}

char	*gl_strchr(char *s, int c)
{
	char	*p;
	char	smb;

	p = s;
	smb = (char)c;
	while (*p && *p != smb)
		p++;
	if (*p == smb)
		return (p);
	return (0);
}

char	*gl_strdup(char *s1)
{
	int		i;
	char	*dest;
	int		l;

	i = 0;
	l = gl_strlen(s1);
	dest = (char *)malloc((l + 1) * sizeof(char));
	if (!dest)
	{
		free (dest);
		return (0);
	}
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*gl_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	j = -1;
	str = malloc(sizeof(char) * (gl_strlen(s1) + gl_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
	{
		str[i] = s1[i];
	}
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}

char	*gl_addost(char *s, int len)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (gl_strlen(s) < len)
		len = gl_strlen(s);
	if (gl_strlen(s) == 0)
		return (gl_strdup(""));
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
