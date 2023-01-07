/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_revers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:22:17 by realdahh          #+#    #+#             */
/*   Updated: 2023/01/05 15:00:46 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_node **a_stack)
{
	if (rotate(a_stack) == -1)
		return (-1);
	put_endl_fd("ra", 1);
	return (0);
}

int	rb(t_node **b_stack)
{
	if (rotate(b_stack) == -1)
		return (-1);
	put_endl_fd("rb", 1);
	return (0);
}

int	rr(t_node **a_stack, t_node **b_stack)
{
	if (list_size(*a_stack) < 2 || list_size(*b_stack) < 2)
		return (-1);
	rotate(a_stack);
	rotate(b_stack);
	put_endl_fd("rr", 1);
	return (0);
}
