/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:11:55 by lefendie          #+#    #+#             */
/*   Updated: 2021/11/26 15:43:25 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_skip(const char *str, const char sep)
{
	while (*str == sep)
		str++;
	return (str);
}

int	ft_list_size(const char *str, const char sep, char ***result)
{
	int	list_size;

	list_size = 0;
	if (!str)
		return (0);
	while (*str)
	{
		while (*str && *str == sep)
			str++;
		if (*str && *str != sep)
		{
			list_size++;
			while (*str && *str != sep)
				str++;
		}
	}
	list_size++;
	*result = malloc(sizeof(char *) * list_size + 1);
	if (!*result)
		return (FAILURE);
	return (list_size);
}

int	ft_word_size(const char *str, const char sep)
{
	int	word_size;

	word_size = 0;
	while (str[word_size] && str[word_size] != sep)
		word_size++;
	return (word_size);
}

int	ft_alloc_split_list(const char *s, char **result, int list_size, char c)
{
	int	i;
	int	word_size;

	i = 0;
	while (i < list_size - 1)
	{
		s = ft_skip(s, c);
		word_size = ft_word_size(s, c);
		result[i] = malloc(sizeof(char) * (word_size + 1));
		if (!result[i])
			return (FAILURE);
		s += word_size;
		i++;
	}
	return (SUCCESS);
}

char	**ft_split(const char *s, const char c)
{
	char	**result;
	int		i;
	int		j;
	int		word_size;
	int		list_size;

	list_size = ft_list_size(s, c, &result);
	ft_alloc_split_list(s, result, list_size, c);
	if (!list_size)
		return (result);
	i = 0;
	while (*s && list_size != 1 && *(ft_skip(s, c)))
	{
		s = ft_skip(s, c);
		word_size = ft_word_size(s, c);
		j = 0;
		while (*s && j < word_size)
			result[i][j++] = *s++;
		result[i][j] = '\0';
		i++;
	}
	result[i] = 0;
	return (result);
}
