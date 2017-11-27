/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <raphaelkriefbm@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 18:44:56 by rkrief            #+#    #+#             */
/*   Updated: 2017/11/27 17:14:41 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getnextline.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		lenstr;
	size_t		i;

	i = 0;
	lenstr = ft_strlen((char*)src);
	while (i < len)
	{
		if (i > lenstr)
			dst[i] = '\0';
		else
			dst[i] = src[i];
		i++;
	}
	return (dst);
}
