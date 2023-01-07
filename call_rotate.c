/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:17:32 by realdahh          #+#    #+#             */
/*   Updated: 2023/01/05 10:15:59 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_node **a_stack)
{
	if (reverse_rotate(a_stack) == -1)
		return (-1);
	put_endl_fd("rra", 1);
	return (0);
}

int	rrb(t_node **b_stack)
{
	if (reverse_rotate(b_stack) == -1)
		return (-1);
	put_endl_fd("rrb", 1);
	return (0);
}

int	rrr(t_node **a_stack, t_node **b_stack)
{
	if (list_size(*a_stack) < 2 || list_size(*b_stack) < 2)
		return (-1);
	reverse_rotate(a_stack);
	reverse_rotate(b_stack);
	put_endl_fd("rrr", 1);
	return (0);
}
