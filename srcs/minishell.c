#include "minishell.h"

static void show_prompt(void)
{
	char cmds[1024];
	getcwd(cmds,1024);
	write(1, cmds, ft_strlen(cmds));
	write(1, "$ ", 3);
}

// static void	run_shell(t_minishell *shell)
// {
// 	int	i;

// 	i = -1;
// 	if(shell->cmd->cmd == NULL)
// 		shell->cmd->cmd = " ";
// 	while (++i < BLTIN_NUM)
// 		if (!ft_strcmp(shell->cmd->cmd, blt_str(i)))
// 			(*blt_func(i))(shell);
// }


void	minishell(char **en)
{
	int		status;
	char	*line;
	t_minishell *shell;
	// char	**cmd;

	status = 1;
	while (status)
	{
		show_prompt();
		if(get_next_line(0,&line) > 0)
		{
			shell = (t_minishell *)malloc(sizeof(t_minishell));
			shell = parse_data(line);
			while(shell->next)
			{
				printf("%s\n",shell->cmd->cmd);
				shell = shell->next;
			}
			// run_shell(shell);
			// free(line);
			//freeshell(shell)
		}
	}
	free(line);
	(void)en;
}