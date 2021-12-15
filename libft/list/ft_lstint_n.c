/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstint_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:18:22 by user42            #+#    #+#             */
/*   Updated: 2021/10/07 21:48:14 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstint_n(t_list *list, int n)
{
	while (n && list)
	{
		list = list->next;
		n--;
	}
	return (ft_lstint(list));
}
