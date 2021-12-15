/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsufx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:53:48 by manjaro           #+#    #+#             */
/*   Updated: 2021/11/26 15:43:21 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsufx(char *sufx, char *str)
{
	char	*new_str;
	int		i;
	int		size;

	i = -1;
	size = ft_strlen(sufx) + ft_strlen(str) + 1;
	new_str = malloc(sizeof(char) * size);
	if (!new_str)
		return (0);
	while (str[++i])
		new_str[i] = str[i];
	while (*sufx)
	{
		new_str[i] = *sufx;
		i++;
		sufx++;
	}
	new_str[i] = '\0';
	return (new_str);
}
