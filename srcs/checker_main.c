#include "../includes/push_swap.h"

# define BUFFER_SIZE 1

static int		returned(char *p_na, char **rem)
{
	if (p_na)
		return (1);
	else
	{
		free(*rem);
		*rem = NULL;
		return (0);
	}
}

static void		ft_free(char *tmp, char **rem)
{
	free(tmp);
	free(*rem);
	*rem = NULL;
}

static char		*check_remainder(char **rem, char **line)
{
	char *p_na;
	char *tmp;

	p_na = NULL;
	*line = ft_strdup("");
	if (*rem != NULL)
	{
		if ((p_na = ft_strchr(*rem, '\n')) != NULL)
		{
			*p_na = '\0';
			tmp = *line;
			*line = ft_strjoin(*line, *rem);
			free(tmp);
			tmp = *rem;
			*rem = ft_strdup(++p_na);
			free(tmp);
		}
		else
		{
			tmp = *line;
			*line = ft_strdup(*rem);
			ft_free(tmp, rem);
		}
	}
	return (p_na);
}

int				get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	long		byte_read;
	char		*p_n;
	static char *rem;
	char		*tmp;

	if (BUFFER_SIZE <= 0 || !(line) || (read(fd, buf, 0) < 0))
		return (-1);
	p_n = check_remainder(&rem, line);
	while (!p_n && (byte_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[byte_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			rem = ft_strdup(++p_n);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)))
			return (-1);
		free(tmp);
	}
	return (returned(p_n, &rem));
}

void check_line(t_tools *t, char *line) {

    if (!ft_strncmp(line, "sa", ft_strlen(line))) {
        swap_a(t);
    } else if (!ft_strncmp(line, "sb", ft_strlen(line))) {
        swap_b(t);
    } else if (!ft_strncmp(line, "ss", ft_strlen(line))) {
        swap_ab(t);
    } else if (!ft_strncmp(line, "pa", ft_strlen(line))) {
        push_a(t);
    } else if (!ft_strncmp(line, "pb", ft_strlen(line))) {
        push_b(t);
    } else if (!ft_strncmp(line, "ra", ft_strlen(line))) {
        rotate_a(t);
    } else if (!ft_strncmp(line, "rb", ft_strlen(line))) {
        rotate_b(t);
    } else if (!ft_strncmp(line, "rr", ft_strlen(line))) {
        rotate_ab(t);
    } else if (!ft_strncmp(line, "rra", ft_strlen(line))) {
        reverse_rotate_a(t);
    } else if (!ft_strncmp(line, "rrb", ft_strlen(line))) {
        reverse_rotate_b(t);
    } else if (!ft_strncmp(line, "rrr", ft_strlen(line))) {
        reverse_rotate_ab(t);
    } else {
        ft_putendl_fd("Error", 1);
        exit(-1);
    }
}

int main(int argc, char **argv)
{
    char *line = NULL;
    t_tools	t;

    check_args(argc);
    init_struct_tools(&t);
	create_two_tabs(&t, argv, argc);
	sort_tab(&t);
	add_indexes_to_list(&t);
	while (1) {
        if (get_next_line(STDIN_FILENO, &line) == 0)
        {
            check_line(&t, line);
            break ;
        }
        check_line(&t, line);
    }
	if (check_if_sorted_a(&t) == 0)
	{
		ft_putendl_fd("OK", 1);
	}
	else
		ft_putendl_fd("KO", 1);
	return (0);

	/* TODO negative integers
	   TODO Two CTRL-D */
}