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
#include <stdlib.h>
#include <unistd.h>

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