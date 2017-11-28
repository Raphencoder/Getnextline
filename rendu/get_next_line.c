/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:05:18 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/28 20:06:20 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
	int			j;
	static char **str;
	char		buf[BUFF_SIZE + 1];
	size_t			i;

	if (str == NULL)
		str = (char**)malloc(sizeof(char*) * 1000);
	j = fd;
	if (fd < 0)
		return (-1);
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		i = ft_strlen(buf);
		if (str[j] == NULL)
		{
			str[j] = (char*)malloc(sizeof(char) * (i + 1));
			str[j] = ft_strcpy(str[j], buf);
		}
		else	
			str[j] = ft_strjoin(str[j], buf);
	}
//	ft_putstr(str[j]);
	
	if (i == -1)
		return (-1);
	if (str[j] == NULL)
		return (0);
	if (*str[j] == '\0')
	{
		**line = '\0';
		return (0);
	}
	i = 0;
	while (str[j][i] != '\n' && str[j][i])
		i++;
	*line = (char*)malloc(sizeof(char));
	*line = ft_strnew(i);
	ft_strncpy(*line, str[j], i);
	str[j] = str[j] + i + 1;
//	ft_putstr(str[j]);
	return (1);
}
/*
int main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	char	**line;
	int		ret;
	line = (char**)malloc(sizeof(char*));
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	
	get_next_line(fd, line);
	ft_putstr(*line);
	get_next_line(fd, line);
	ft_putstr(*line);
	get_next_line(fd, line);
	ft_putstr(*line);
	get_next_line(fd, line);
	ft_putstr(*line);

	return (0);
} */
