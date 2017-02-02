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

int					file_read(char *file_path, t_meta *meta)
{
	int				fd;
	t_cell			*matrix;
	t_biggest		biggest;

	fd = open(file_path, O_RDONLY);
	matrix = read_on_memory(fd, *meta);
	count_square(*meta, matrix);
	biggest = check_biggest_square(matrix);
	display_cells(*meta, matrix, biggest);
	free(matrix);
	close(fd);
	return (0);
}

int					main(int argc, char **argv)
{
	t_meta			meta;
	int				i;

	if (argc < 2)
	{
		read_stdin();
		if (map_is_valid("./tmp/tmp", &meta))
			file_read("./tmp/tmp", &meta);
		else
			write(2, "map error\n", 10);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (map_is_valid(argv[i], &meta))
			file_read(argv[i], &meta);
		else
			write(2, "map error\n", 10);
		i++;
	}
	return (0);
}
