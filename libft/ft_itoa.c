/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:44:30 by mbounoui          #+#    #+#             */
/*   Updated: 2024/11/08 16:18:10 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = n * -1;
		count += 1;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	hand_num(long *num, int *sign)
{
	*num *= -1;
	*sign = -1;
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	long	nb;
	char	*result;

	if (n == 0)
		return (ft_strdup("0"));
	sign = 1;
	nb = n;
	len = count_len(nb);
	if (nb < 0)
		hand_num(&nb, &sign);
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len)
	{
		result[--len] = '0' + (nb % 10);
		nb = nb / 10;
	}
	if (sign == -1)
		result[0] = '-';
	return (result);
}
