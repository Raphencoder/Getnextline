/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:05:18 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/29 19:58:17 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_movefwrd(char **str, int fd, int i)
{
	char	*strnew;
	int		k;
	int		l;

	l = 0;
	k = i;
	while (str[fd][k])
	{
		k++;
		l++;
	}
	strnew = ft_strnew(l);
	ft_strncpy(strnew, str[fd] + i, l);
	ft_strdel(str + fd);
	strnew[l] = '\0';
	return (strnew);
}

void		ft_fillstr(char **str, char *buf, int fd)
{
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
	if (i == -1)
		return (-1);
	if (str[fd] == NULL)
		return (0);
	if (*str[fd] == '\0')
	{
		*line = ft_strnew(0);
		return (0);
	}
	i = 0;
	while (str[fd][i] != '\n' && str[fd][i])
		i++;
	*line = ft_strnew(i);
	ft_strncpy(*line, str[fd], i);
	str[fd] = ft_movefwrd(str, fd, i + 1);
	return (1);
}

int			find_endl(char *buf, char **str, int fd)
{
	size_t	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			break ;
		i++;
	}
	if (i == ft_strlen(buf))
		return (0);
	ft_fillstr(str, buf, fd);
	if (i == 0)
		return (0);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int			j;
	static char **str;
	char		buf[BUFF_SIZE + 1];
	int			i;
	int			clone;

	if (str == NULL)
		str = ft_memalloc(sizeof(char *) * 4865);
	if (fd < 0)
		return (-1);
	while ((j = read(fd, buf, BUFF_SIZE)) > 0)
	{	
		if (buf[j] == '\0')
		{
			clone = j;
			j = -5;
		}
		buf[j] = '\0';
		if (find_endl(buf, str, fd))
			break ;
		ft_fillstr(str, buf, fd);
	}
	i = ft_error(j, str, fd, line);
	if (i == 0)
		return (0);
	if (i == -1)
		return (-1);
//	if (j == -5 && clone ==  BUFF_SIZE)
//		return (0);
//	if (clone == 0 && j == -5)
//		return (0);
	return (1);
	return (0);
}
