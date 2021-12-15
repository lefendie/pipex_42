/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:42:44 by lefendie          #+#    #+#             */
/*   Updated: 2021/12/08 19:43:29 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 *  Function: connect_parent_temp
 *  -------------------------
 *  Connect the parent stdin and stdout to the pipe duo without affecting 
 *  them, this is allowed by using duplicates of the pipe duo ends
 *  
 *  pipe_duo: Pipe duo for bi-directional data transfer
 *
 *	Returns: Success state
 */

int	connect_parent_temp(int **pipe_duo)
{
	int	receive_temp;
	int	send_temp;

	receive_temp = dup(pipe_duo[1][0]);
	send_temp = dup(pipe_duo[0][1]);
	if (dup2(receive_temp, 0) < -1)
		return (FAILURE);
	close(receive_temp);
	if (dup2(send_temp, 1) < -1)
		return (FAILURE);
	close(send_temp);
	return (SUCCESS);
}

/*
 *  Function: connect_parent
 *  -------------------------
 *  Connect the parent stdin and stdout to the pipe duo
 *
 *  pipe_duo: Pipe duo for bi-directional data transfer
 *
 *	Returns: Success state
 */

int	connect_parent(int **pipe_duo)
{
	if (!branch_read_to(pipe_duo[1], 0))
		return (FAILURE);
	if (!branch_write_to(pipe_duo[0], 1))
		return (FAILURE);
	return (SUCCESS);
}

/*
 *  Function: connect_child
 *  -------------------------
 *  Connect the parent stdin and stdout to the pipe duo
 *
 *  pipe_duo: Pipe duo for bi-directional data transfer
 *
 *	Returns: Success state
 */

int	connect_child(int **pipe_duo)
{
	if (!branch_read_to(pipe_duo[0], 0))
		return (FAILURE);
	if (!branch_write_to(pipe_duo[1], 1))
		return (FAILURE);
	return (SUCCESS);
}

/*
 *  Function: create_pipe_duo
 *  -------------------------
 *  Creates a list containing a pipe duo intended for
 *  bi-directional data transfer between processes
 *
 *  pipe_duo: Address of the pipe_list to create
 *
 *  Returns: Success state
 */

int	create_pipe_duo(int ***pipe_duo)
{
	int		*pipe_send;
	int		*pipe_receive;

	*pipe_duo = malloc(sizeof(int *) * 2);
	if (!*pipe_duo)
		return (FAILURE);
	pipe_receive = malloc(sizeof(int) * 2);
	if (!*pipe_receive)
		return (FAILURE);
	pipe_send = malloc(sizeof(int) * 2);
	if (!*pipe_send)
		return (FAILURE);
	pipe(pipe_send);
	pipe(pipe_receive);
	(*pipe_duo)[0] = pipe_send;
	(*pipe_duo)[1] = pipe_receive;
	return (SUCCESS);
}
