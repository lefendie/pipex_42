/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefendie <leon.efendiev@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:34:06 by lefendie          #+#    #+#             */
/*   Updated: 2021/12/09 11:29:38 by lefendie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
 *  Function: free_str_list
 *  -------------------------
 *  Frees the list of string passed as parameter
 *  
 *  str_list: List of string to free
 *
 */

void	free_str_list(char **str_list)
{
	int	i;

	i = 0;
	while (str_list[i])
		free(str_list[i++]);
	free(str_list);
}

/*
 *  Function: get_path_env
 *  -------------------------
 *  Get the PATH environnement variable from envp
 *  
 *  envp: List containing the environnement variables
 *
 *	Returns: PATH environnement
 */

char	**get_path_env(char **envp)
{
	char	**path_env;

	while (*envp && !lb_isstr_start_equal(*envp, "PATH="))
		envp++;
	if (!*envp)
		return (NULL);
	path_env = ft_split(*envp + 5, ':');
	return (path_env);
}

/*
 *  Function: get_bin
 *  -------------------------
 *  Get the bin path to the command, it is used in case if the command is
 *  not in the current directory
 *  
 *  command:	Command to execute
 *  envp:			List containing the environnement variables
 *
 *	Returns: Binary path
 */

char	*get_bin(char *command, char **envp)
{
	char	**path_list;
	char	*full_path;
	char	*temp;
	int		i;

	path_list = get_path_env(envp);
	temp = ft_strsufx("/", path_list[0]);
	full_path = ft_strjoin(temp, command);
	free(temp);
	i = 1;
	while (access(full_path, F_OK) == -1 && path_list[i])
	{
		free(full_path);
		temp = ft_strsufx("/", path_list[i++]);
		full_path = ft_strjoin(temp, command);
		free(temp);
	}
	free_str_list(path_list);
	if (!path_list[i])
	{
		free(full_path);
		return (command);
	}
	return (full_path);
}

/*
 *  Function: check_command
 *  -------------------------
 *  Check if the command exists
 *  
 *  command:	Command to execute
 *  envp:			List containing the environnement variables
 *
 *	Returns: Success state
 */

int	check_command(char **argv, char **envp)
{
	char	**func_arg;
	char	*bin_path;
	int		i;
	char	*command;

	if (lb_isstr_equal(argv[1], "here_doc"))
		command = argv[3];
	else
		command = argv[2];
	func_arg = ft_split(command, SPACE);
	bin_path = get_bin(func_arg[0], envp);
	if (!bin_path)
		return (FAILURE);
	i = 0;
	if (!lb_isstr_equal(bin_path, command))
		free(bin_path);
	if (*func_arg)
	{
		while (func_arg[i])
			free(func_arg[i++]);
	}
	free(func_arg);
	return (SUCCESS);
}
