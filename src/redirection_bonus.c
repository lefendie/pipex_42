/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:57:18 by lefendie          #+#    #+#             */
/*   Updated: 2021/12/15 11:21:26 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 *  Function: redirect_write_end
 *  -------------------------
 *  Allows the transfer of data to a file by writing to the end
 *  of the file
 *
 *	file: File where the redirection is done
 *
 *  Returns: Success state
 */

int	redirect_write_end(char *file)
{
	int	fd_file;

	fd_file = open(file, O_WRONLY | O_APPEND | O_CREAT,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_file == -1)
		return (0);
	if (dup2(fd_file, 1) < -1)
		return (FAILURE);
	close(fd_file);
	return (SUCCESS);
}

/*
 *  Function: transfer_pipe
 *  -------------------------
 *  Allows the transfer of data between commands
 *
 *  pipe_duo:		List containing a duo of pipes
 *  cmd_list:		List containing the commands
 *  cmd_count:	Number of commands
 *  envp:				List containing the envirronement variables
 *
 *  Returns: Success state
 */

int	transfer_pipe(int **pipe_duo, char **cmd_list,
		int cmd_count, char **envp)
{
	int	id;
	int	i;

	i = -1;
	while (++i < cmd_count)
	{
		id = fork();
		if (!id)
		{
			if (!connect_child(pipe_duo))
				return (FAILURE);
			exec_command(cmd_list[i], envp);
		}
		if (!connect_parent_temp(pipe_duo))
			return (FAILURE);
	}
	wait(NULL);
	if (!connect_parent(pipe_duo))
		return (FAILURE);
	return (SUCCESS);
}

/*
 *  Function: here_doc
 *  -------------------------
 *  Handles the here_doc and the transfer of the data to the next command
 *
 *	argv: Parameters of the program
 *	hrdc_pipe: Pipe only for the here_doc
 *
 *  Returns: Success state
 */

int	here_doc(char **argv, int *hrdc_pipe)
{
	char	*line;

	line = "";
	while (!lb_isstr_equal(line, argv[2]))
	{
		ft_get_next_line(0, &line);
		if (!lb_isstr_equal(line, argv[2]))
		{
			write(hrdc_pipe[1], line, ft_strlen(line));
			write(hrdc_pipe[1], "\n", 1);
		}
	}
	if (!branch_read_to(hrdc_pipe, 0))
		return (FAILURE);
	return (SUCCESS);
}
