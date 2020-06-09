/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frchaban <frchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 12:13:06 by frchaban          #+#    #+#             */
/*   Updated: 2020/06/09 18:20:14 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_greater_redir(char **cmd, int i, int flag)
{
	int fd;

	flag == 1 ? cmd[i] = NULL : 0;
	if ((fd = open(cmd[++i],O_CREAT| O_RDWR | O_TRUNC,0644)) < 0)
	{
		ft_error("minishell: no such file or directory: ", NULL, cmd[i]);
		exit(EXIT_FAILURE);
	}
	else
	{
		dup2(fd,STDOUT_FILENO);
		close (fd);
	}
	return (fd);
}

int		ft_greatgreat_redir(char **cmd,int i, int flag)
{
	int fd;

	flag == 1 ? cmd[i] = NULL : 0;
	if ((fd = open(cmd[++i],O_CREAT| O_RDWR | O_APPEND,0644)) < 0)
	{
		ft_error("minishell: no such file or directory: ", NULL, cmd[i]);
		exit(EXIT_FAILURE);
	}
	else
	{
		dup2(fd,STDOUT_FILENO);
		close (fd);
	}
	return (fd);
}

int		ft_lesser_redir(char **cmd, int i, int flag)
{
	int fd;

	flag == 1 ? cmd[i] = NULL : 0;
	if ((fd = open(cmd[++i],O_RDONLY,0)) < 0)
	{
		ft_error("minishell: no such file or directory: ", NULL, cmd[i]);
		flag == 1 ? exit(EXIT_FAILURE) : 0;
	}
	else
	{
		dup2(fd,STDIN_FILENO);
		close (fd);
	}
	return (fd);
}

int		ft_redir(char **cmd , int flag)
{
	int i;
	int res;

	i = -1;
	res = 0;
	while(cmd[++i])
	{
		if (ft_strequ(cmd[i],">"))
			res = ft_greater_redir(cmd, i++, flag);
		else if (ft_strequ(cmd[i],">>"))
			res = ft_greatgreat_redir(cmd, i++, flag);
		else if (ft_strequ(cmd[i],"<"))
		{
			res = ft_lesser_redir(cmd, i++, flag);
		}
	}
	return (res);
}