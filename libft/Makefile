# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anifanto <anifanto@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/03 11:38:11 by anifanto          #+#    #+#              #
#    Updated: 2022/07/04 17:59:56 by anifanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

.SILENT:

LIST =	ft_atoi.c			ft_bzero.c			ft_calloc.c\
		ft_isalnum.c		ft_isalpha.c		ft_isascii.c\
		ft_isdigit.c		ft_isprint.c		ft_memchr.c\
		ft_memcmp.c			ft_memcpy.c			ft_memmove.c\
		ft_memset.c			ft_strchr.c			ft_strcmp.c\
		ft_strdup.c			ft_strlcat.c		ft_strlcpy.c\
		ft_strlen.c			ft_strncmp.c		ft_strnstr.c\
		ft_strrchr.c		ft_tolower.c		ft_toupper.c\
		ft_substr.c			ft_strjoin.c		ft_strtrim.c\
		ft_split.c			ft_itoa.c			ft_strmapi.c\
		ft_striteri.c		ft_putchar_fd.c		ft_putstr_fd.c\
		ft_putendl_fd.c		ft_putnbr_fd.c		ft_atod.c\
		ft_lstnew.c			ft_lstadd_front.c	ft_lstsize.c\
		ft_lstlast.c		ft_lstadd_back.c	ft_lstdelone.c\
		ft_lstclear.c		ft_lstiter.c		ft_lstmap.c\
		ft_isspace.c\
		gnl/get_next_line.c 		gnl/get_next_line_utils.c \

OBJ = $(LIST:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

SAVE = "\033[s"
CUT = "\033[K"
GREEN = "\033[32m"
RESET = "\033[0m"
UP = "\033[A"

$(NAME) :	$(OBJ)
	gcc -c $(FLAGS) $(LIST)
	ar rc $(NAME) $(OBJ)

all : $(NAME)

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $(<:%.c=%.o)
	@echo $(SAVE)$(CUT)$(GREEN) Compiling with $(CFLAGS)...$(RESET)
	@echo $(CUT) $(GREEN)[$^] to [$@] $(RESET)
	@printf $(UP)$(UP)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
