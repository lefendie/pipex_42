/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:40:16 by lefendie          #+#    #+#             */
/*   Updated: 2021/12/08 15:41:45 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

int	close_pipe(int *pipe);
int	branch_read_to(int pipe[2], int fd);
int	branch_write_to(int pipe[2], int fd);

#endif
