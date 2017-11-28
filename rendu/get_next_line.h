/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 11:39:26 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/28 20:38:49 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1 
# include <fcntl.h>
# include "./libft/libft.h"

int		get_next_line(int const fd, char **line);
#endif
