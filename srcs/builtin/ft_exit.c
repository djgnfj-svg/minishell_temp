/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 14:12:44 by kwonhyukbae       #+#    #+#             */
/*   Updated: 2021/09/18 16:47:30 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//exit_status 란?
// void 형으로 교체해야할듯?
// 만약 메인문을 끝까지 진행하려면
// 파이프라인이 진행중이면 exit는 작동하지 않음
int		ft_isdigit_str(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (!ft_isdigit(str[idx]))
			return (0);
		idx++;
	}
	return (1);
}

void	print_exit(void)
{
	ft_putstr_fd("exit\n", 2);
}

int		ft_exit(t_minishell *shell)
{
	int ac;
	int status;
	char **buff;

	if (shell->pre_flag)
		return 0;
	buff = ft_split(shell->cmd->buff, ' ');
	ac = 0;
	status = 1;
	while (buff[ac])
		ac++;
	if (ac == 1)
		print_exit();
	else if (ac == 2 && ft_isdigit_str(buff[1]))
		status = ft_atoi(buff[1]);
	else if (ac > 2 && ft_isdigit_str(buff[1]))
	{
		ft_putstr_fd("exit\n", 2);
		print_error1("exit", "too many argments");
		status = 1;
		return status;
	}
	else
	{
		print_error2("exit", buff[1], "numeric argument required");
		status = 255;
	}
	return (status);
}
