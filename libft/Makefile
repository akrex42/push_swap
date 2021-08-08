# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akrex <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/06 16:39:35 by akrex             #+#    #+#              #
#    Updated: 2020/11/06 19:21:25 by akrex            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_calloc.c \
	ft_atoi.c \
	ft_strncmp.c \
	ft_strdup.c \
	ft_strnstr.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_strtrim.c \
	ft_strmapi.c \
	ft_split.c \
	ft_itoa.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstadd_back.c \
	ft_lstsize.c \
	ft_lstlast.c \
#	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstclear.c \
	ft_lstmap.c
	
HEAD	= libft.h
OBJS	= ${SRCS:.c=.o}
NAME	= libft.a
CC		= gcc
#CFLAGS	= -Wall -Wextra -Werror -O3
RM		= rm -f


all: $(NAME) 

$(NAME): $(OBJS) 
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJSBONUS)
	ar rcs $(NAME) $(OBJS) $(OBJSBONUS)

clean:
		$(RM) $(OBJS) $(OBJSBONUS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
