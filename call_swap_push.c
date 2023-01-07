/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_swap_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:30:33 by realdahh          #+#    #+#             */
/*   Updated: 2023/01/05 15:02:45 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_node **a_stack)
{
	if (swap (a_stack) == -1)
		return (-1);
	put_endl_fd("sa", 1);
	return (0);
}

int	sb(t_node **b_stack)
{
	if (swap(b_stack) == -1)
		return (-1);
	put_endl_fd("sb", 1);
	return (0);
}

int	ss(t_node **a_stack, t_node **b_stack)
{
	if (list_size(*a_stack) < 2 || list_size(*b_stack) < 2)
		return (-1);
	swap(a_stack);
	swap(b_stack);
	put_endl_fd("ss", 1);
	return (0);
}

int	pa(t_node **a_stack, t_node **b_stack)
{
	if (push(a_stack, b_stack) == -1)
		return (-1);
	put_endl_fd("pa", 1);
	return (0);
}

int	pb(t_node **a_stack, t_node **b_stack)
{
	if (push(b_stack, a_stack) == -1)
		return (-1);
	put_endl_fd("pb", 1);
	return (0);
}
