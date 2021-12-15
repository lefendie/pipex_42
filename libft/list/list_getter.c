/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_getter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:57:30 by lefendie          #+#    #+#             */
/*   Updated: 2021/09/16 11:05:56 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstint(t_list *list)
{
	return (*(int *)list->content);
}

int	ft_lstint_next(t_list *list)
{
	return (*(int *)list->next->content);
}
