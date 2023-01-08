/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:58:17 by realdahh          #+#    #+#             */
/*   Updated: 2023/01/08 15:59:46 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted(t_node **stack)
{
	t_node	*top;

	top = *stack;
	while (top && top-> next)
	{
		if (top->data > top->next->data)
			return (0);
		top = top->next;
	}
	return (1);
}

void	init_sort(t_node **stack, char **av)
{
	t_vars	vars;

	vars.i = 0;
	vars.x = 0;
	while (av[++vars.x])
	{
		vars.arg = ft_split(av[vars.x], ' ');
		if (vars.arg[1] == NULL)
		{
			vars.new = new_list(ft_atoi(av[vars.x]));
			add_back_list(stack, vars.new);
		}
		else
		{
			while (vars.arg[vars.i])
			{
				vars.new = new_list(ft_atoi(vars.arg[vars.i]));
				add_back_list(stack, vars.new);
				vars.i++;
			}
		}
		ft_free(vars.arg);
	}
	ft_index(stack);
}

int	dup_check(t_node **a_stack)
{
	t_node	*tmp;
	t_node	*tmp1;

	tmp = *a_stack;
	while (tmp)
	{
		tmp1 = *a_stack;
		while (tmp1)
		{
			if ((tmp1->data == tmp->data) && (tmp1->index != tmp->index))
				return (1);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

static void	err_check(t_node **a_stack, t_node **b_stack)
{
	if (dup_check(a_stack) == 1)
	{
		free_stack(a_stack);
		free_stack(b_stack);
		write(1, "Error\n", 6);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_node	**a_stack;
	t_node	**b_stack;

	if (ac < 2)
		exit(0);
	check_arg(av);
	a_stack = (t_node **)malloc(sizeof(t_node));
	b_stack = (t_node **)malloc(sizeof(t_node));
	*a_stack = NULL;
	*b_stack = NULL;
	init_sort(a_stack, av);
	err_check(a_stack, b_stack);
	if (ft_sorted(a_stack))
	{
		free_stack(a_stack);
		free_stack(b_stack);
		return (0);
	}
	ft_sorting(a_stack, b_stack);
	free_stack(a_stack);
	free_stack(b_stack);
	return (0);
}
