/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:30:38 by realdahh          #+#    #+#             */
/*   Updated: 2023/01/05 18:36:31 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first 2 elements at the top of stack
int	swap(t_node **stack)
{
	t_node	*top;
	t_node	*num;

	if (list_size(*stack) < 2)
		return (-1);
	top = *stack;
	num = top->next;
	top->data = num->data;
	top->index = num->index;
	return (0);
}

//Take the first element at the top of s1 and put it at the top of s2
int	push(t_node **stack_dst, t_node **stack_src)
{
	t_node	*tmp;
	t_node	*top_src;
	t_node	*top_dst;

	if (list_size(*stack_src) == 0)
		return (-1);
	top_dst = *stack_dst;
	top_src = *stack_src;
	tmp = top_src;
	top_src = top_src->next;
	*stack_src = top_src;
	if (!top_dst)
	{
		top_dst = tmp;
		top_dst->next = NULL;
		*stack_dst = top_dst;
	}
	else
	{
		tmp->next = top_dst;
		*stack_dst = tmp;
	}
	return (0);
}

//Shift up all elements of (s) by 1,The first element becomes the last one
int	rotate(t_node **stack)
{
	t_node	*top;
	t_node	*bottom;

	if (list_size(*stack) < 2)
		return (-1);
	top = *stack;
	bottom = last_list(top);
	*stack = top->next;
	top->next = NULL;
	bottom->next = top;
	return (0);
}

//Shift down all elements of (s) by 1.The last element becomes the first one
int	reverse_rotate(t_node **stack)
{
	t_node	*top;
	t_node	*bottom;

	if (list_size(*stack) < 2)
		return (-1);
	top = *stack;
	bottom = last_list(top);
	while (top)
	{
		if (top->next->next == NULL)
		{
			top->next = NULL;
			break ;
		}
		top = top->next;
	}
	bottom->next = *stack;
	*stack = bottom;
	return (0);
}
