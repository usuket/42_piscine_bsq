/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakakib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 14:20:19 by ysakakib          #+#    #+#             */
/*   Updated: 2017/01/30 14:21:10 by ysakakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>
#include <bsq_header.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1
#define MEM_BUF 20000

t_meta				read_map_meta(int fd)
{
	t_meta		meta;
	char		buffer;

	set_meta(&meta, fd);
	read(fd, &buffer, 1);
	count_width(&meta, fd);
	return (meta);
}

t_cell				*read_on_memory(int fd, t_meta meta)
{
	t_cell		*cell_array;
	char		buffer;
	int			i;

	cell_array = malloc(sizeof(t_cell) * (meta.width * meta.height + MEM_BUF));
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
			break ;
	}
	i = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer != '\n')
		{
			cell_array[i].cell = buffer;
			i++;
		}
	}
	return (cell_array);
}

void				display_cells(t_meta meta, t_cell *cells, t_biggest big)
{
	int i;
	int x;
	int y;

	y = 0;
	while (y < meta.height)
	{
		x = 0;
		while (x < meta.width)
		{
			i = yx_to_index(meta, y, x);
			if (is_biggest_cells(meta, i, big))
				ft_putchar(meta.full);
			else if (cells[i].cell == meta.obstacle)
				ft_putchar(meta.obstacle);
			else
				ft_putchar(meta.empty);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

int					file_read(char *file_path)
{
	int				fd;
	t_meta			meta;
	t_cell			*matrix;
	t_biggest		biggest;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("File open failed.\n");
		return (1);
	}
	meta = read_map_meta(fd);
	close(fd);
	fd = open(file_path, O_RDONLY);
	matrix = read_on_memory(fd, meta);
	count_square(meta, matrix);
	biggest = check_biggest_square(matrix);
	display_cells(meta, matrix, biggest);
	free(matrix);
	close(fd);
	return (0);
}

int					main(int argc, char **argv)
{
	int i;

	if (argc < 2)
	{
//		printf("need argv\n");
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		file_read(argv[i]);
		i++;
	}
	return (0);
}
