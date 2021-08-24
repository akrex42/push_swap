#include "../includes/push_swap.h"

char	*ft_strappend(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i])
	{
		i++;
	}
	str = (char *)malloc(i + 2);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s);
	return (str);
}

int	main_cycle_read(char *buf, char **line)
{
	char	save;
	int		flag;
	int		count;

	count = 0;
	flag = 0;
	save = 0;
	while (read(STDIN_FILENO, buf, 1) > 0)
	{
		save = buf[0];
		buf[1] = '\0';
		if (buf[0] == '\n')
			break ;
		*line = ft_strappend(*line, buf[0]);
		flag = 1;
		count++;
	}
	free(buf);
	if ((*line[0] == '\0' && save == '\n') || (save != '\n' && count != 0))
		return (2);
	if (flag == 1)
		return (1);
	return (0);
}

void	ft_error(char *line)
{
	free(line);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(-1);
}

int	get_next_line(char **line)
{
	char	*buf;

	buf = (char *)malloc(2);
	*line = malloc(1);
	if ((*line == NULL) || !buf)
		return (-1);
	*line[0] = '\0';
	buf[0] = -1;
	buf[1] = -2;
	return (main_cycle_read(buf, line));
}

int	checks_for_cycle_b(t_tools *t, int len, int i)
{
	check_tail_ab(t, len);
	i++;
	t->b = t->head_b;
	if (ft_lstsize(t->b) <= 3)
	{
		if (t->tail_b)
			sort_stack_three_elems_b(t);
		check_tail_ab(t, len);
	}
	return (i);
}
