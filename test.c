
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <termios.h>
# include <errno.h>


size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(src);
	if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	len = 0;
	while (src[len])
	{
		dest[len] = src[len];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}


int		ft_puterror_fd(char *s1, char *s2, int fd)
{
	ft_putstr_fd(s1, fd);
	ft_putendl_fd(s2, fd);
	return (127);
}
static int do_redir(char *log_file, char **g_envp)
{
	int argc = 2;
	int fd;
	int status;
	char **temp;

	temp = (char **)malloc(sizeof(char *) * 3);

	temp[0] = "echo ";
	temp[1] = "test asdf";
	temp[2] = NULL;
	if((fd = open(log_file,  O_WRONLY | O_CREAT | O_TRUNC, 0744)) < 0)
	{
		ft_puterror_fd(log_file, ": No such file or directory", 2);
		return 0;
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if(execve("/bin/echo",temp ,g_envp) == -1)
		fprintf(stderr, "에러 %s\n", strerror(errno));
}

static char			**copy_envp(char **envs)
{
	char	**new;
	int		i;

	i = 0;
	while (envs[++i] != NULL)
		i++;
	if (!(new = malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = -1;
	while (envs[++i])
		new[i] = ft_strdup(envs[i]);
	new[i] = NULL;
	return (new);
}

int main(int ac, char **av, char **envp)
{
	char **g_envp = copy_envp(envp);
	(void)ac;
	(void)av;
	int i;
	int ret;
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		ret = do_redir("test.txt",g_envp);
		exit(ret);
	}
	waitpid(pid, &status, 0);
}


// int main(int ac, char **av, char **g_envp)
// {
// 	pid_t pid;
// 	int fd;
// 	pid = fork();

// 	if(pid == 0)
// 	{
// 		int i;
// 		char **temp;
// 		char **buff;
// 		fd = open("test.txt", O_RDWR | O_CREAT | S_IROTH, 0644);
// 		if(fd < 0)
// 		{
// 			perror("error");
// 			exit(-1);
// 		}
// 		dup2(fd, STDOUT_FILENO);
// 		close(fd);
// 		temp = (char **)malloc(sizeof(char *) * 3);
// 		temp[0] = "echo ";
// 		temp[1] = "test";
// 		temp[2] = NULL;
// 		if(fd != 0)
// 		{
// 			if(execve("/bin/echo", temp ,g_envp) == -1)
// 				fprintf(stderr, "에러 %s\n", strerror(errno));
// 			// fprintf(stderr, "test");
// 			exit(127);
// 		}
// 		exit(0);
// 	}
// 	waitpid(pid,NULL,0);
// }