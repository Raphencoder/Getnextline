/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:05:18 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/28 22:14:21 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_error(int i, char **str, int j, char **line)
{
	if (i == -1)
		return (-1);
	if (str[j] == NULL)
		return (0);
	if (*str[j] == '\0')
	{
		**line = '\0';
		return (0);
	}
	return (5);
}

int	ft_next(char **str, int j, char **line)
{
	int i;

	i = 0;
	while (str[j][i] != '\n' && str[j][i])
		i++;
	*line = (char*)malloc(sizeof(char));
	*line = ft_strnew(i);
	ft_strncpy(*line, str[j], i);
	str[j] = str[j] + i + 1;
	return (1);
}

int get_next_line(const int fd, char **line)
{
	int			j;
	static char **str;
	char		buf[BUFF_SIZE + 1];
	int			i;
	int			o;

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
			str[j] = ft_strdup(buf);
		else	
			str[j] = ft_strjoin(str[j], buf);
	}
	o = ft_error(i, str, j, line);
	if (o != 5)
		return (o);
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
	while (get_next_line(fd, line))
		ft_putstr(*line);
	return (0);
} */
