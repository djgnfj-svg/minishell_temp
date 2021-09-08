#ifndef MINISHELL_H
# define MINISHELL_H

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
	t_list next;
	t_cmd	cmd;
	//글로벌 변수로하거나 구조체에 담아서 움직여도 좋을듯
	int		exit_status;
	// 파이프라인 마지막 쪽에 있으면 안되는 명령어들을 위해서 필요할듯
	int		pipe_flag;
}	t_minishell;

int		main(int argc, char *argv[], char *envp[]);
void	minishell(char **en);

/*
builtin commands
*/
char	*blt_str(int i);
int		(*blt_func(int i))(char *line, char **en);
int		ft_echo(char *line, char **en);
int		ft_cd(char *line, char **en);
int		ft_pwd(char *line, char **en);
int		ft_export(char *line, char **en);
int		ft_unset(char *line, char **en);
int		ft_env(char *line, char **en);
int		ft_exit(char *line, char **en);


int print_error1(char *msg, char *err_num);
int print_error2(char *msg1, char* msg2, char *err_num);

char			*find_en(char *key, char **en);
#endif