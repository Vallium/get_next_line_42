/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 12:43:29 by aalliot           #+#    #+#             */
/*   Updated: 2014/11/15 19:36:53 by aalliot          ###   ########.fr       */
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
	int				i;

	buff = ft_strnew(BUFF_SIZE);
	if (!fd || BUFF_SIZE <= 0)
		return (-1);
	if (mem)
		str = ft_strdup(mem);
	while (!ft_strchr(str, '\n'))
	{
		if (!read(fd, &buff, BUFF_SIZE))
		{
			i = 0;
			break;
		}
		str = ft_strjoin(str, buff);
	}
	*line = ft_strsub(str, 0, ft_strchr(str, '\n') - str - 1);
	mem = ft_strsub(str, ft_strchr(str, '\n') - str + 1, \
			ft_strlen(ft_strchr(str, '\n')));
	return(i == 0 ? 0 : 1);
}

int			main()
{
	char	*str;
	char	**line;
	int		fd;

	fd = open("static.c", O_RDONLY);
	while (get_next_line(fd, line))
		printf("%s\n", line);
	return (0);
}
