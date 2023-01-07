/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:17:31 by realdahh          #+#    #+#             */
/*   Updated: 2023/01/07 13:57:59 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//  int	duplicate(int nb, char **new, int i)
// {
// 	i++;
// 	while (new[i])
// 	{
// 		if (ft_atoi(new[i]) == nb)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

static int	is_num(char *nb)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (!nb)
		return (0);
	if (nb[0] == '+' || nb[0] == '-')
		if (nb[1] == '\0')
			return (0);
	if (nb[x] == '+' || nb[x] == '-')
		x++;
	if (nb[0] == '0')
		while (nb[x] != '\0' && nb[x] == '0')
			x++;
	while (nb[x])
	{
		if (nb[x] >= '0' && nb[x] <= '9')
			x++;
		else
			return (0);
	}
	return (1);
}

void	ft_error(char *str, char **new)
{
	ft_free(new);
	put_endl_fd(str, 1);
	exit(0);
}

void	check_arg(char **av)
{
	t_vars	vars;
	char	**new;

	vars.x = 0;
	while (av[++vars.x])
	{
		new = ft_split(av[vars.x], ' ');
		if (new[0] == NULL)
			ft_error("Error", new);
		else
		{
			vars.i = -1;
			while (new[++vars.i])
			{
				vars.nb = ft_atoi(new[vars.i]);
				if (!is_num(new[vars.i]) || av[vars.x] == NULL)
					ft_error("Error", new);
				else if (vars.nb < -2147483648 || vars.nb > 2147483647)
					ft_error("Error", new);
			}
		}
		ft_free (new);
	}
}
