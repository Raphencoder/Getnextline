/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:05:18 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/28 16:53:41 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getnextline.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int get_next_line(const int fd, char **line)
{
	static char *str;
	char		buf[BUFF_SIZE + 1];
	int			i;

	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		i = ft_strlen(buf);
		if (str == NULL)
		{
			str = (char*)malloc(sizeof(char) * (i + 1));
			str = ft_strcpy(str, buf);
		}
		else	
			str = ft_strjoin(str, buf);
	}
	if (*str == '\0')
	{
		**line = '\0';
		return (0);
	}
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	*line = ft_strnew(i + 1);
	ft_strncpy(*line, str, i);
	str = str + i + 1;
	return (1);
}
/*
int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		ret;
	fd = open(argv[1], O_RDONLY);
		ret = get_next_line(fd, &line);
	printf("%d - %s\n", ret, line);
		ret = get_next_line(fd, &line);
	printf("%d - %s\n", ret, line);
		ret = get_next_line(fd, &line);
	printf("%d - %s\n", ret, line);
		ret = get_next_line(fd, &line);
	printf("%d - %s\n", ret, line);
		ret = get_next_line(fd, &line);
	printf("%d - %s\n", ret, line);
		ret = get_next_line(fd, &line);
	printf("%d - %s\n", ret, line);
		ret = get_next_line(fd, &line);
	printf("%d - %s\n", ret, line);
	return (0);
} */
