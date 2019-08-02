#include "prototypes.h"

void		ft_error(void)
{
	ft_putendl("Error");
	exit(EXIT_FAILURE);
}

void		ft_fill_map(t_map *m, char *line, int y)
{
	int		i;
	char		**tab;

	i = -1;
	tab = ft_strsplit(line, ' ');
	while (tab[++i])
	{
		m->tab[y][i] = ft_atoi(tab[i]);
	}
	if (!m->w)
		m->w = i;
	if (i && m->w != i)
		ft_error();

}

void		ft_read_file(t_map *m, char *file_name)
{
	int	fd;
	int	y;
	char	*line;

	fd = open(file_name, O_RDONLY);
	y = 0;
	m->w = 0;
	if (ft_get_next_line(fd, &line) && line)
	{
		ft_fill_map(m, line, y++);
		while (ft_get_next_line(fd, &line))
			ft_fill_map(m, line, y++);
		m->h = y;
		if (!m->w || !m->h)
			ft_error();
	}
	else
		ft_error();

}
