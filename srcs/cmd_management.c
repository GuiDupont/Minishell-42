#include "minishell.h"

void	prompt(void)
{
	ft_printf("%s", "minishell $> ");
}

char ***parse_cmd(char *line)
{
	char **cmd;
	char ***data;
	int i;

	i = -1;
	cmd = ft_split(line, ';');
	ft_printf("%d\n", ft_count_split(cmd));
	if (!(data = malloc(sizeof(*data) * ft_count_split(cmd))))
		return (NULL);
	data[ft_count_split(cmd)] = NULL;
	while (cmd[++i])
	{
		cmd[i] = ft_strtrim_freed(cmd[i], " ");
		data[i] = ft_split(cmd[i],' ');
	}
	free(line);
	ft_free_2dim(cmd);
	return (data);
}

char ***get_cmd(void)
{
	char *line;

	prompt();
	while (get_next_line(0, &line)!= 1)
	{
	}
	return(parse_cmd(line));
}

void	launch(char **cmd, int *status, t_env *envir)
{
	if (ft_strcmp(cmd[0],"echo") == 0)
		return;
	else if (ft_strcmp(cmd[0],"cd") == 0)
		cd_builtin(cmd);
	else if (ft_strcmp(cmd[0],"pwd") == 0)
		pwd_builtin();
	else if (ft_strcmp(cmd[0],"export") == 0)
		return;
	else if (ft_strcmp(cmd[0],"unset") == 0)
		return;
	else if (ft_strcmp(cmd[0],"env") == 0)
		return;
	else if (ft_strcmp(cmd[0],"exit") == 0)
		*status = exit_builtin();
	else
	{
		execute(cmd, envir);
	}
}

