/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:05:18 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/30 13:20:28 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_movefwrd(char **str, int fd, int i)
{
	char	*strnew;
	int		k;
	int		j;

	j = 0;
	k = i;
	while (str[fd][k])
	{
		k++;
		j++;
	}
	strnew = ft_strnew(j);
	ft_strncpy(strnew, str[fd] + i - 1, j);
	ft_strdel(str + fd);
	return (strnew);
}

void		ft_fillstr(char **str, char *buf, int fd)
{
//	ft_putstr(buf);
	char *tmp;

	if (str[fd] == NULL)
		str[fd] = ft_strdup(buf);
	else
	{
		tmp = str[fd];
		str[fd] = ft_strjoin(tmp, buf);
		if (tmp)
			ft_strdel(&tmp);
	}
}

int			ft_error(int i, char **str, int fd, char **line)
{
//	ft_putstr(str[fd]);
	if (i == -1)
		return (-1);
	if (str[fd] == NULL)
		return (0);
	if (str[fd][0] == '\0')
	{
		ft_strdel(str + fd);
		*line = ft_strnew(10);
		return (0);
	}
	i = 0;
	while (str[fd][i] != '\n' && str[fd][i])
		i++;
	*line = ft_strnew(i);
//	ft_putstr(str[fd]);
//	ft_putnbr(i);
//	ft_putstr("||");
	ft_strncpy(*line, str[fd], i);
//	ft_putstr(*line);
	str[fd] = ft_movefwrd(str, fd, i + 1);
	return (1);
}

int			find_endl(char *buf, char **str, int fd)
{
//	ft_putstr(str[fd]);
	size_t	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			ft_fillstr(str, buf, fd);
	//		ft_putstr(str[fd]);
			return (1);
		}
		i++;
	}
//	ft_putstr(str[fd]);
	if (i == ft_strlen(buf))
		return (0);
	if (i == 0)
		return (-1);
	ft_fillstr(str, buf, fd);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	int			j;
	static char **str;
	char		buf[BUFF_SIZE + 1];
	int			i;
	int			tmp;

	if (str == NULL)
		str = ft_memalloc(sizeof(char *) * 4865);
	if (fd < 0)
		return (-1);
	while ((j = read(fd, buf, BUFF_SIZE)) > 0)
	{	
		buf[j] = '\0';
		if ((tmp = find_endl(buf, str, fd)) == 1)
		{
//			ft_putstr(str[fd]);
			break ;
		}
//		if (tmp == -1)
//		{
//			*line = ft_strnew(10);
//			return (0);
//		}
//		ft_putstr(str[fd]);
		ft_fillstr(str, buf, fd);
//		ft_putstr(str[fd]);
	}
//	ft_putstr(str[fd]);
//	ft_putstr(str[fd]);
	i = ft_error(j, str, fd, line);
//	ft_putstr(str[fd]);
	if (i == 0)
		return (0);
	if (i == -1)
		return (-1);
	return (1);
}
/*
int main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	char	*line;
	int		ret;
	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
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
