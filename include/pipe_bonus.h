/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:42:29 by lefendie          #+#    #+#             */
/*   Updated: 2021/12/08 15:43:39 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_BONUS_H
# define PIPE_BONUS_H

int	connect_parent_temp(int **pipe_duo);
int	connect_parent(int **pipe_duo);
int	connect_child(int **pipe_duo);
int	create_pipe_duo(int ***pipe_duo);

#endif
