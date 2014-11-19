/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 12:43:29 by aalliot           #+#    #+#             */
/*   Updated: 2014/11/18 18:58:15 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					get_next_line(int fd, char **line)
{
	static char		*mem;
	char			*str;
	char			buff[BUFF_SIZE + 1];
	int				ret;

	if (!line || !fd || BUFF_SIZE <= 0)
		return (-1);
	if (mem)
		str = ft_strdup(mem);
	while (!ft_strchr(str, '\n'))
	{
		if (!(ret = read(fd, buff, BUFF_SIZE)))
			break ;
		buff[ret] = 0;
		str = ft_strjoin(str, buff);
	}
	*line = ft_strsub(str, 0, ft_strchr(str, '\n') - str);
	mem = ft_strsub(str, ft_strchr(str, '\n') - str + 1, \
			ft_strlen(ft_strchr(str, '\n')));
	free(str);
	return (ret == 0 ? 0 : 1);
}
