/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:36:53 by anifanto          #+#    #+#             */
/*   Updated: 2022/04/20 12:52:00 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*check_ost(char **ost);
char	*join_end(char **ost);
int		check_read(char *ost, int fd, int len);
int		gl_strlen(char *s);
char	*gl_strchr(char *s, int c);
char	*join_end(char **ost);
char	*gl_strdup(char *s1);
char	*gl_strjoin(char *s1, char *s2);
char	*gl_addost(char *s, int len);

#endif
