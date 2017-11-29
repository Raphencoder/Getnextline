/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:05:18 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/29 13:28:26 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char 	*ft_strjoinfree(char **s1, int j, char *s2)
{
	char    *str;

//	ft_putstr(s1[j]);
//	ft_putstr(s2);
	if (*s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char*)ft_memalloc(ft_strlen(s1[j]) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	str = ft_strcat(str, s1[j]);
	ft_putstr(str);
	str = ft_strcat(str, s2);
	free (s1[j]);
//	ft_putstr(str);
	return (str);
}

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
	i = 0;
	while (str[j][i] != '\n' && str[j][i])
		i++;
	*line = (char*)malloc(sizeof(char));
	*line = ft_strnew(i);
	ft_strncpy(*line, str[j], i);
	str[j] = str[j] + i + 1;
	return (1);
}

char **ft_tmp(char **str, int j)
{
	char *tmp;

	tmp = (char*)malloc(sizeof(char) * ft_strlen(str[j]));
	tmp = str[j];
	free (str[j]);
	str[j] = (char*)malloc(sizeof(char) * ft_strlen(tmp));
	str[j] = tmp;
	free (tmp);
	return (str);
}

int	find_endl(char *buf, char **str, int j)
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
	if (str[j] == NULL)
	{
	//	ft_tmp(str, j);
		str[j] = ft_strdup(buf);
	}
	else
	{
//		ft_tmp(str, j);
//		ft_putstr(buf);
		str[j] = ft_strjoin(str[j], buf);
	}
	return (1);
}


int get_next_line(const int fd, char **line)
{
	int			j;
	static char **str;
	char		buf[BUFF_SIZE + 1];
	int			i;
//	char		*clone;
	if (str == NULL)
		str = (char**)malloc(sizeof(char*) * 1000000);
	j = fd;
	if (fd < 0)
		return (-1);
	while ((i = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[i] = '\0';
		if (find_endl(buf, str, j))
			break ;
		i = ft_strlen(buf);
		if (str[j] == NULL)
		{
		//	ft_putstr(buf);
//			ft_tmp(str, j);
			str[j] = ft_strdup(buf);
		//	ft_putstr(str[j]);
		}
		else	
		{
//			ft_putstr(buf);
			str[j] = ft_strjoin(str[j], buf);
//			ft_putstr(str[j]);
//			clone  = ft_strjoin(str[j], buf);
		
//			free (clone);
		}
	}
	i = ft_error(i, str, j, line);
	if (i == 0)
		return (0);
	if (i == -1)
		return (-1);
	return (1); 
}

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
}
