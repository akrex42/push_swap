NAME		= push_swap

NAME_1		= checker

SRCS_DIR	= ./srcs/

SRCS		= $(filter-out ./srcs/checker_main.c, $(wildcard $(SRCS_DIR)*.c))

SRCS_1		= $(filter-out ./srcs/push_swap.c, $(wildcard $(SRCS_DIR)*.c))

OBJS		= $(filter-out ./srcs/checker_main.o, $(patsubst %.c,%.o,$(SRCS)))

OBJS_1		= $(filter-out ./srcs/push_swap.o, $(patsubst %.c,%.o,$(SRCS_1)))

DEPENDS		= $(patsubst %.c,%.d,$(SRCS))

DEPENDS_1	= $(patsubst %.c,%.d,$(SRCS_1))

HEADERS		= ./includes/push_swap.h

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -g

LDFLAGS		= -Wall -Wextra -Werror -g

RM			= rm -f

LIBFTDIR	= ./libft/

LIBFT		= $(LIBFTDIR)libft.a

all: $(NAME) $(NAME_1) $(LIBFT)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(LDFLAGS) $^ -o $@

$(NAME_1): $(OBJS_1) $(LIBFT)
	$(CC) $(LDFLAGS) $^ -o $@

$(SRCS_DIR)%.o: $(SRCS_DIR)%.c $(LIBFT) Makefile
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(LIBFT):
	make -C $(LIBFTDIR)

-include $(DEPENDS)

clean:
		$(RM) $(OBJS) $(OBJS_1) $(DEPENDS) $(DEPENDS_1)
		make -C $(LIBFTDIR) clean

fclean: clean
		make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re