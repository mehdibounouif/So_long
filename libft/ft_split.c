/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbounoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:52:36 by mbounoui          #+#    #+#             */
/*   Updated: 2024/11/08 16:54:34 by mbounoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*copy_word(char const *str, char c, int *len)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	*len = i;
	word = (char *)malloc((i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_memmove(word, str, i);
	word[i] = '\0';
	return (word);
}

static void	free_split(char **ars)
{
	int	i;

	i = 0;
	if (!ars)
		return ;
	while (ars[i])
	{
		free(ars[i]);
		i++;
	}
	free(ars);
}

static void	check_and_put(char **ars, char const *s, char c)
{
	int	i;
	int	index;
	int	len;

	i = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] && s[index] == c)
			index++;
		if (s[index])
		{
			len = 0;
			ars[i] = copy_word(&s[index], c, &len);
			if (!ars[i])
			{
				free_split(ars);
				return ;
			}
			i++;
			index += len;
		}
	}
	ars[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**ar;
	int		count;

	if (!s)
		return (NULL);
	count = count_word(s, c);
	ar = (char **)malloc((count + 1) * sizeof(char *));
	if (!ar)
		return (NULL);
	check_and_put(ar, s, c);
	return (ar);
}
