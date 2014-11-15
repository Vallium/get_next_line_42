/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 13:43:33 by aalliot           #+#    #+#             */
/*   Updated: 2014/11/15 14:18:56 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFF_SIZE 42

#include <stdio.h>
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>

void	function(int fd)
{
	static char *str;
	char buffer[BUFF_SIZE + 1];

	read(fd, &buffer, BUFF_SIZE);
	str = ft_strjoin(str, buffer);
	printf("%s\n\n\n", str);
}

int	main(void)
{
	char *str;
	int c = 0;
	int fd;

	fd = open("static.c", O_RDONLY);
	while (c++ < 10)
		function(fd);
	return (0);
}

/*
while (ft_strchr(str, '\n'))
{
	buffer = read(fd, &buffer, BUFF_SIZE);
	str= ft_strjoin(str, buffer);
}
*line = ft_strsub(str, 0, ft_strchr(str, '\n') - str - 1);
memory = ft_strsub(str, ft_strchr(str, '\n') - str + 1, \
				   ft_strlen(ft_strchr(str, '\n')));
*/
