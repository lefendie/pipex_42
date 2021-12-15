/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:14:40 by lefendie          #+#    #+#             */
/*   Updated: 2021/12/08 19:56:12 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 *  Function: branch_write_to
 *  -------------------------
 *  Connects the write end of the pipe to the designated file descriptor
 *  
 *  pipe: Pipe to branch
 *  fd:		file descriptor to branch to
 *
 *	Returns: Success state
 */

int	branch_write_to(int pipe[2], int fd)
{
	close(pipe[0]);
	if (dup2(pipe[1], fd) < -1)
		return (FAILURE);
	close(pipe[1]);
	return (SUCCESS);
}

/*
 *  Function: branch_read_to
 *  -------------------------
 *  Connects the read end of the pipe to the designated file descriptor
 *  
 *  pipe: Pipe to branch
 *  fd:		file descriptor to branch to
 *
 *	Returns: Success state
 */

int	branch_read_to(int pipe[2], int fd)
{
	close(pipe[1]);
	if (dup2(pipe[0], fd) < -1)
		return (FAILURE);
	close(pipe[0]);
	return (SUCCESS);
}

/*
 *  Function: close_pipe
 *  -------------------------
 *  Closes entirely the pipe passed as parameter
 *  
 *  pipe: Pipe to close
 *
 *	Returns: Success state
 */

int	close_pipe(int *pipe)
{
	if (close(pipe[0]) == -1)
		return (FAILURE);
	if (close(pipe[1]) == -1)
		return (FAILURE);
	return (SUCCESS);
}
