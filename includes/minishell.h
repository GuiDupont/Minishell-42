/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frchaban <frchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 11:32:44 by frchaban          #+#    #+#             */
/*   Updated: 2020/06/08 13:44:06 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/errno.h>
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/libftprintf.h"

typedef struct 		s_env
{
	char 			*key;
	char 			*content;
	struct s_env 	*next;
}					t_env;

void		echo(char *content, int option);
char		***get_cmd(void);
void		execute(char **cmd, t_env *envir);
void		launch(char **cmd, int *status, t_env *envir);

void		cd_builtin(char **cmd);
void		pwd_builtin(void);
void		echo_builtin(char **cmd);
int			exit_builtin(void);



#endif
