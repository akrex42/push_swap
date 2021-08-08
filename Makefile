NAME		= push_swap

SRCS_DIR	= ./srcs/

SRCS		= $(wildcard $(SRCS_DIR)*.c)

HEADERS		= ./includes/push_swap.h

OBJS		= $(patsubst %.c,%.o,$(SRCS))

DEPENDS		= $(patsubst %.c,%.d,$(SRCS))

CC			= gcc

#CFLAGS		= -Wall -Wextra -Werror

#LDFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

LIBFTDIR	= ./libft/

LIBFT		= $(LIBFTDIR)libft.a

all: $(NAME) $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(LDFLAGS) $^ -o $@

$(SRCS_DIR)%.o: $(SRCS_DIR)%.c $(LIBFT) Makefile
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(LIBFT):
	make -C $(LIBFTDIR)

-include $(DEPENDS)

clean:
		$(RM) $(OBJS) $(DEPENDS)
		make -C $(LIBFTDIR) clean

fclean: clean
		make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re