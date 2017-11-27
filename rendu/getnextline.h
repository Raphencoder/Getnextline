/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:39:26 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/27 20:01:43 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 100
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int		get_next_line(int const fd, char **line);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	*ft_memalloc(size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);

#endif
