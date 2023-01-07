/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:09:49 by realdahh          #+#    #+#             */
/*   Updated: 2023/01/07 13:37:53 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int nb)
{
	if (nb >= '0' && nb <= '9')
		return (1);
	else
		return (0);
}

long	ft_atoi(char *str)
{
	long int	i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && (str[i] == '\v' || str[i] == '\r'
			|| str[i] == '\t' || str[i] == ' '
			|| str[i] == '\f' || str[i] == '\n'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	return (result * sign);
}

void	put_endl_fd(char *str, int fd)
{
	if (str)
	{
		put_str_fd(str, fd);
		put_char_fd ('\n', fd);
	}
}

void	put_char_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	put_str_fd(char *str, int fd)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}
