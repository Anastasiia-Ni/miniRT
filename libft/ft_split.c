/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:26:43 by anifanto          #+#    #+#             */
/*   Updated: 2022/07/04 17:24:35 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(const char *str, char set)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && (*str == set))
			str++;
		if (*str && (*str != set))
		{
			count++;
			while (*str && (*str != set))
				str++;
		}
	}
	return (count);
}

static char	*ft_word(const char *str, char set)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != set)
		i++;
	word = (char *)ft_calloc((i + 1), sizeof(char));
	i = 0;
	if (!word)
		return (NULL);
	while (str[i] && (str[i] != set))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	ft_fill(char const *s, char c, char	**array, int i)
{
	while (*s)
	{
		while (*s && (*s == c))
			s++;
		if (*s && (*s != c))
		{
			array[i] = ft_word(s, c);
			if (!array[i])
			{
				while (i)
					free (array[i--]);
				free (array);
				return (0);
			}
			i++;
			while (*s && (*s != c))
				s++;
		}
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**array;

	i = 0;
	if (!s)
	{
		array = (char **)ft_calloc(1, sizeof(char));
		if (!array)
			return (0);
		return (&array[0]);
	}
	array = (char **)ft_calloc((ft_size(s, c) + 1), sizeof(char *));
	if (!array)
		return (NULL);
	i = ft_fill(s, c, array, i);
	array[i] = ((void *)0);
	return (array);
}
