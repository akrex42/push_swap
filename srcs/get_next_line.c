#include "../includes/push_swap.h"
#define BUFFER_SIZE 1

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

int				get_next_line(t_tools *t, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	long		byte_read;
	char		*p_n;
	static char *rem;
	char		*tmp;

	if (BUFFER_SIZE <= 0 || !(line) || (read(t->fd, buf, 0) < 0))
		return (-1);
	p_n = check_remainder(&rem, line);
	while (!p_n && (byte_read = read(t->fd, buf, BUFFER_SIZE)))
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