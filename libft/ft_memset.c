/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:47:58 by mbounoui          #+#    #+#             */
/*   Updated: 2024/11/16 02:52:41 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h> 

void	*ft_memset(void *s, int value, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		*((unsigned char *)(s + i)) = (unsigned char)value;
		i++;
	}
	return (s);
}
/*
int	main()
{
	int n = 1;
	ft_memset(&n, 255, 4);
	printf("%d", n);
}
*/
