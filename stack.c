/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:53:05 by realdahh          #+#    #+#             */
/*   Updated: 2023/01/06 10:02:56 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorting(t_node **a_stack, t_node **b_stack)
{
	if (list_size(*a_stack) <= 5)
		simple_sort(a_stack, b_stack);
	else
		radix_sort(a_stack, b_stack);
}

void	ft_index(t_node **stack)
{
	t_node	*top;
	int		number;

	number = 0;
	top = find_next_min(stack);
	while (top)
	{
		top->index = number++;
		top = find_next_min(stack);
	}
}

void	free_stack(t_node **stack)
{
	t_node	*top;
	t_node	*t;

	top = *stack;
	while (top)
	{
		t = top;
		top = top->next;
		free(t);
	}
	free(stack);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}
