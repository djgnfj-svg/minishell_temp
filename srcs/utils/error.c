/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysong <ysong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 07:31:22 by ysong             #+#    #+#             */
/*   Updated: 2021/09/08 08:04:37 by ysong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int print_error1(char *msg, char *err_num)
{
	ft_putstr_fd("minishell :", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err_num, 2);
	return -1;
}
int print_error2(char *msg1, char *msg2, char *err_num)
{
	ft_putstr_fd("minishell :", 2);
	ft_putstr_fd(msg1, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg2, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err_num, 2);
	return -1;
}