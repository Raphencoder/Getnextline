/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 20:53:24 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/27 21:04:48 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:05:18 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/27 20:52:36 by rkrief           ###   ########.fr       */
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
	
	i = 0;
	if (read(fd, buf, BUFF_SIZE))
	{
		if (buf[0] == NULL)
			return (0);
		i = ft_strlen(buf);
		if (str == NULL)
		{
			str = (char*)malloc(sizeof(char) * (i + 1));
			str = ft_strcpy(str, buf);
		}
		else
			str = (char*)malloc(sizeof(char) * (ft_strlen(str) + (i + 1)));
	}
	*line = (char*)malloc(sizeof(char) * (ft_strlen(str)));
	i = 0;
	while (str[i] != '\n')
		i++;
	ft_strncpy(*line, str, i);
	str = str + i + 1;
	return (0);
}

int main(int argc, char **argv)
{
	int		fd;
	char	**line;

	fd = open(argv[1], O_RDONLY);
	line = (char**)malloc(sizeof(char*));
	get_next_line(fd, line);
	ft_putstr(*line);
	get_next_line(fd, line);
	ft_putstr(*line);
	get_next_line(fd, line);
	ft_putstr(*line);
	get_next_line(fd, line);
	ft_putstr(*line);

	return (0);
}
