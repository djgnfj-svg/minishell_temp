#include "minishell.h"

static void show_prompt(void)
{
	write(1, "minishell>", ft_strlen("minishell>"));
}

static void	run_shell(char *line, char **en)
{
	int	i;
	char *temp;

	i = -1;
	temp = ft_split(line,' ')[0];
	while (++i < BLTIN_NUM)
		if (!ft_strcmp(temp, blt_str(i)))
			(*blt_func(i))(line, en);
}

void	minishell(char **en)
{
	int		status;
	char	*line;
	// char	**cmd;

	// parse_data
	status = 1;
	while (status)
	{
		show_prompt();
		if(get_next_line(0,&line) > 0)
		{
			//parse_data
			run_shell(line, en);
			free(line);
		}
	}
	free(line);
	(void)en;
}