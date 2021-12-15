/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:13:02 by user42            #+#    #+#             */
/*   Updated: 2021/10/05 14:16:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstn(t_list **list, int n)
{
	while (n && *list)
	{
		*list = (*list)->next;
		n--;
	}
}
