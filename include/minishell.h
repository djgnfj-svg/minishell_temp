#ifndef MINISHELL_H
# define MINISHELL_H


# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <termios.h>
# include <errno.h>
# include "../libft/includes/libft.h"

# define STDIN 			0
# define STDOUT 		1
# define STDERR 		2

# define BLTIN_NUM 7
extern char		**g_envp;



/*


*/

/*
next,
prev,
pipe_flag,
pre_flag,
cmd, type, arg <- option, text,
*/

typedef struct s_cmd
{
	char *cmd;
	char *buff;
	//t_minishell next_perv
}				t_cmd;

typedef struct s_minishell
{
	struct	s_minishell *next;
	struct	s_minishell *prev;
	struct	s_minishell *head;
	t_cmd	*cmd;
	int		exit_status;
	int		pipe_flag;
	int		pre_flag;
	int		re_flag;
	int		fds[2];
}	t_minishell;

int		main(int argc, char *argv[], char *envp[]);
void	minishell(char **en);

/*
builtin commands
*/
char	*blt_str(int i);
int		(*blt_func(int i))(t_minishell *shell);
int		run_blt(t_minishell *shell, int i);

int		ft_echo(t_minishell *shell);
int		ft_cd(t_minishell *shell);
int		ft_pwd(t_minishell *shell);
int		ft_export(t_minishell *shell);
int		ft_unset(t_minishell *shell);
int		ft_env(t_minishell *shell);
int		ft_exit(t_minishell *shell);

/*
parse.c
*/
t_minishell *parse_data(char *line);
int list_rewind(t_minishell **shell);
/*
utils.c
*/
int print_error1(char *msg, char *err_num);
int print_error2(char *msg1, char* msg2, char *err_num);
void child_process(t_minishell *shell);
int pipe_process(t_minishell *shell);

/*
freeshell.c
*/
void freeshell(t_minishell **shell);

char			*find_en(char *key, char **en);
#endif