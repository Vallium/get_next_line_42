/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 12:43:29 by aalliot           #+#    #+#             */
/*   Updated: 2014/11/17 15:39:09 by aalliot          ###   ########.fr       */
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
	char			*buff;
	int				ret;

	buff = ft_strnew(BUFF_SIZE + 1);
	if (!fd || BUFF_SIZE <= 0)
		return (-1);
	if (mem)
		str = ft_strdup(mem);
	while (!ft_strchr(str, '\n'))
	{
		if (!(ret = read(fd, buff, BUFF_SIZE)))
			break;
		buff[ret] = 0;
		str = ft_strjoin(str, buff);
	}
	*line = ft_strsub(str, 0, ft_strchr(str, '\n') - str);
	mem = ft_strsub(str, ft_strchr(str, '\n') - str + 1, \
			ft_strlen(ft_strchr(str, '\n')));
	free(str);
	return (ret == 0 ? 0 : 1);
}

int			main()
{
	char	*str;
	char	*line;
	int		fd;

	fd = open("static.c", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
	}
	return (0);
}
