/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:05:36 by realdahh          #+#    #+#             */
/*   Updated: 2023/01/06 11:41:06 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_node **a_stack, t_node **b_stack)
{
	int	size;

	size = list_size (*a_stack);
	if (ft_sorted(a_stack) || size == 0 || size == 1)
		return ;
	if (size == 2)
		sa(a_stack);
	else if (size == 3)
		sort_3numbers(a_stack);
	else if (size == 4)
		sort_4numbers(a_stack, b_stack);
	else if (size == 5)
		sort_5numbers(a_stack, b_stack);
}

void	sort_3nums(t_node **a_stack)
{
	t_node	*top;
	int		min_nb;

	top = *a_stack;
	min_nb = find_minimum(a_stack, -1);
	if (top->next->index == min_nb)
		ra(a_stack);
	else
	{
		sa(a_stack);
		rra(a_stack);
	}
}

void	sort_3numbers(t_node **a_stack)
{
	t_node	*top;
	int		min_nb;
	int		next_min;

	top = *a_stack;
	min_nb = find_minimum(a_stack, -1);
	next_min = find_minimum(a_stack, min_nb);
	if (ft_sorted(a_stack))
		return ;
	if (top->index == min_nb && top->next->index != next_min)
	{
		ra(a_stack);
		sa(a_stack);
		rra(a_stack);
	}
	else if (top->index == next_min)
	{
		if (top->next->index == min_nb)
			sa(a_stack);
		else
			rra(a_stack);
	}
	else
		sort_3nums(a_stack);
}

void	sort_4numbers(t_node **a_stack, t_node **b_stack)
{
	int	box;
	int	min_nb;

	if (ft_sorted(a_stack))
		return ;
	min_nb = find_minimum(a_stack, -1);
	box = find_distance(a_stack, min_nb);
	if (box == 1)
		ra(a_stack);
	else if (box == 2)
	{
		ra(a_stack);
		ra(a_stack);
	}
	else if (box == 3)
		rra(a_stack);
	if (ft_sorted(a_stack))
		return ;
	pb (a_stack, b_stack);
	sort_3numbers (a_stack);
	pa (a_stack, b_stack);
}

void	sort_5numbers(t_node **a_stack, t_node **b_stack)
{
	int	box;

	if (ft_sorted(a_stack))
		return ;
	box = find_distance(a_stack, find_minimum(a_stack, -1));
	if (box == 1)
		ra(a_stack);
	else if (box == 2)
	{
		ra(a_stack);
		ra(a_stack);
	}
	else if (box == 3)
	{
		rra(a_stack);
		rra(a_stack);
	}
	else if (box == 4)
		rra(a_stack);
	if (ft_sorted(a_stack))
		return ;
	pb (a_stack, b_stack);
	sort_4numbers (a_stack, b_stack);
	pa (a_stack, b_stack);
}
