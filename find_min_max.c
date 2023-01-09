/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:44:06 by realdahh          #+#    #+#             */
/*   Updated: 2023/01/05 18:41:15 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_minimum(t_node **stack, int value)
{
	t_node	*top;
	int		min_nb;

	top = *stack;
	min_nb = top->index;
	while (top->next)
	{
		top = top->next;
		if (top->index < min_nb && top->index != value)
			min_nb = top->index;
	}
	return (min_nb);
}

// why here the fun is static 
// Returns the next minimum stack value
t_node	*find_next_min(t_node **stack)
{
	int		m;
	t_node	*top;
	t_node	*min_nb;

	top = *stack;
	min_nb = NULL;
	m = 0;
	if (top)
	{
		while (top)
		{
			if ((top->index == -1) && (!m || top->data < min_nb->data))
			{
				min_nb = top;
				m = 1;
			}
			top = top->next;
		}
	}
	return (min_nb);
}

/ Return the distance between the initial node and the one
//having the sought index
int	find_max_bits(t_node **stack)
{
	t_node	*top_a;
	int		max_number;
	int		max_bits;

	top_a = *stack;
	max_number = top_a->index;
	max_bits = 0;
	while (top_a)
	{
		if (top_a->index > max_number)
			max_number = top_a->index;
		top_a = top_a->next;
	}
	while ((max_number >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

int	find_distance(t_node **stack, int number)
{
	t_node	*top;
	int		box;

	box = 0;
	top = *stack;
	while (top)
	{
		if (top->index == number)
			break ;
		box++;
		top = top->next;
	}
	return (box);
}
