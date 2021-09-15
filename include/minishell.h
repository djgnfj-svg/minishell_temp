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

// # include <signal.h>
// # include <sys/types.h>
// # include <sys/stat.h>

// # define PATH_MAX 1024
# define BLTIN_NUM 7
extern char		**g_envp;

typedef struct s_cmd
{
	char *cmd;
	char *buff;
}				t_cmd;

typedef struct s_minishell
{
	struct	s_minishell *next;
	struct	s_minishell *prev;
	struct	s_minishell *head;
	t_cmd	*cmd;
	int		exit_status;
	int		pipe_flag;
	int		fds[2];
}	t_minishell;

int		main(int argc, char *argv[], char *envp[]);
void	minishell(char **en);

/*
builtin commands
*/
char	*blt_str(int i);
int		(*blt_func(int i))(t_minishell *shell);
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

/*
utils.c
*/
int print_error1(char *msg, char *err_num);
int print_error2(char *msg1, char* msg2, char *err_num);

char			*find_en(char *key, char **en);
#endif