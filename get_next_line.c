/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 12:43:29 by aalliot           #+#    #+#             */
/*   Updated: 2014/11/15 16:41:27 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int					get_next_line(int fd, char **line)
{
	static char		*mem;
	char			*str;
	char			buff[BUFF_SIZE + 1];

	if (!fd)
		return (0);
	while (ft_strchr(str, '\n'))
	{
		read(fd, &buff, BUFF_SIZE);
		str = ft_strjoin(str, buff);
	}
	*line = ft_strsub(str, 0, ft_strchr(str, '\n') - str - 1);	`
//	read(fd, &buff, BUFF_SIZE);
}

int			main()
{
	char	*str;
	char	**line;
	int		c;
	int		fd;

	fd = open("static.c", O_RDONLY);
	while (c++ < 10)
		get_next_line(fd, line);
}
