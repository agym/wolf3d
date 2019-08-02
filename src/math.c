/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agym <agym@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 15:25:03 by agym              #+#    #+#             */
/*   Updated: 2019/07/25 23:12:09 by agym             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

/*
** lire et enregistre la map
*/

int			nb_of_lines(char **argv)
{
	char	*line;
	int		cnt;
	int		fd;

	cnt = 0;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		cnt++;
	}
	close(fd);
	return (cnt);
}

int			*tab_cara_to_int(char **lines, int i)
{
	int		j;
	int		*map;

	j = 0;
	if (!(map = (int *)malloc(sizeof(int) * i)))
		return (0);
	while (j < i)
	{
		map[j] = ft_atoi(lines[j]);
		// ft_putnbr(map[j]);
		// write(1, " ", 1);
		j++;
	}
	free_tab(lines);
	return (map);
}

int			nb_cara_in_line1(char *line)
{
	int		i;
	char	**lines;

	i = 0;
	lines = ft_strsplit(line, ' ');
	while (lines[i])
		i++;
	free_tab(lines);
	free(line);
	return (i);
}

int			len(char **line)
{
	int		i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

int			test_fd_argv(int argc, char **argv, t_info *info)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0 && argc == 2)
	{
		ft_putstr("No file");
		ft_putstr(" ");
		ft_putstr(argv[1]);
		free(info);
		close(fd);
		exit(0);
	}
	if (argc != 2)
	{
		ft_putstr("Usage : ./wolf3d <filename>");
		close(fd);
		free(info);
		exit(0);
	}
	return (fd);
}

int			**no_file_map_error(t_info *info, int argc, char **argv, int j)
{
	int		i;
	int		fd;
	char	*line;
	int		**map;
	char	**lines;

	fd = test_fd_argv(argc, argv, info);
	info->map1 = NULL;
	if (!(map = (int **)malloc(sizeof(int *) * nb_of_lines(argv))))
		exit(0);
	if (!(info->map1 = (int **)malloc(sizeof(int *) * nb_of_lines(argv))))
		exit(0);
	while (get_next_line(fd, &line) > 0)
	{
		i = 0;
		lines = ft_strsplit(line, 32);
		i = len(lines);
		map[j++] = tab_cara_to_int(lines, i);
		// ft_putendl("");
		free(line);
	}
	close(fd);
	// ft_putendl("Filling");
	// for(int i = 0; i < 10; i++)
	// {
	// 	for(int j = 0; j < 10; j++)
	// 	{
	// 		ft_putnbr(map[i][j]);
	// 		write(1, " ", 1);
	// 	}
	// 	write(1, "\n", 1);
	// }
	return (map);
}
