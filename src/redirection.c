/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <lefendie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:30:01 by lefendie          #+#    #+#             */
/*   Updated: 2021/12/08 15:39:37 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 *  Function: redirect_write
 *  -------------------------
 *  Redirect the output of the process to a file
 *  
 *  file:	File to write
 *
 *  Returns: Success state
 */

int	redirect_write(char *file)
{
	int	fd_file;

	fd_file = open(file, O_RDWR | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (fd_file == -1)
		return (0);
	if (dup2(fd_file, 1) < -1)
		return (FAILURE);
	close(fd_file);
	return (SUCCESS);
}

/*
 *  Function: redirect_read
 *  -------------------------
 *  Redirect the file to the input of the process
 *  
 *  file:	File to read
 *
 *  Returns: Success state
 */

int	redirect_read(char *file)
{
	int	fd_file;

	fd_file = open(file, O_RDONLY);
	if (fd_file == -1)
		return (0);
	if (dup2(fd_file, 0) < -1)
		return (FAILURE);
	close(fd_file);
	return (SUCCESS);
}

/*
 *  Function: exec_command
 *  -------------------------
 *  Execute the command passed as parameter
 *  
 *  command:	Command to execute
 *  envp:			List containing the environnement variables
 *
 *  Returns: Success state
 */

void	exec_command(char *command, char **envp)
{
	char	**func_arg;
	char	*bin_path;

	func_arg = ft_split(command, SPACE);
	bin_path = get_bin(func_arg[0], envp);
	execve(bin_path, func_arg++, envp);
}
