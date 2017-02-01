/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakakib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:30:18 by ysakakib          #+#    #+#             */
/*   Updated: 2017/01/31 16:30:19 by ysakakib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_header.h>
#include <bsq_header.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define STD_READ_BUF 30

void				read_stdin(void)
{
	char	buffer[STD_READ_BUF];
	int		fd;

	fd = open("./tmp/tmp", O_RDWR | O_CREAT | O_TRUNC, 0666);
	while (read(0, &buffer, STD_READ_BUF) != 0)
	{
		write(fd, &buffer, STD_READ_BUF);
	}
	close(fd);
}

void				set_meta(t_meta *meta, int fd)
{
	char		buffer;
	int			char_count;
	char		*map_length_str;

	char_count = 0;
	map_length_str = malloc(sizeof(char) * (1000000));
	while (read(fd, &buffer, 1) != 0)
	{
		if (buffer == '\n')
			break ;
		if ('0' <= buffer && buffer <= '9')
		{
			map_length_str[char_count] = buffer;
			char_count++;
		}
		else
		{
			meta->empty = buffer;
			read(fd, &meta->obstacle, 1);
			read(fd, &meta->full, 1);
			break ;
		}
	}
	meta->height = ft_atoi(map_length_str);
	free(map_length_str);
}

void				count_width(t_meta *meta, int fd)
{
	char		buffer;

	while (read(fd, &buffer, 1) != 0)
	{
		if (buffer != '\n')
		{
			meta->width++;
		}
		else
			break ;
	}
}

int					map_is_valid(char *file_path)
{
	t_map_valid		val;
	t_meta			meta;

	init_valid(&val);
	val.fd = open(file_path, O_RDONLY);
	set_valid_1(&val, &meta);
	set_valid_2(&val, &meta);
	if (val.row_counter - 1 != val.line_num)
		val.invalid_flag = 1;
	close(val.fd);
	return (!val.invalid_flag);
}
