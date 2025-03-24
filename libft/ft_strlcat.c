/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:56:12 by mbounoui          #+#    #+#             */
/*   Updated: 2024/11/08 16:58:31 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	destlen;
	size_t	srclen;
	size_t	empty_space;
	size_t	i;
	size_t	j;

	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size <= destlen)
		return (size + srclen);
	empty_space = size - destlen - 1;
	if (empty_space > srclen)
		empty_space = srclen;
	i = 0;
	j = destlen;
	while (i < empty_space)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (destlen + srclen);
}
