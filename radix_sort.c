/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:00:31 by realdahh          #+#    #+#             */
/*   Updated: 2023/01/05 10:00:51 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Radix sort of values by binary indexing
void	radix_sort(t_node **a_stack, t_node **b_stack)
{
	int		nb;
	t_node	*top;
	int		bits;
	int		max_bits;
	int		size_lst;

	bits = 0;
	top = *a_stack;
	size_lst = list_size(top);
	max_bits = find_max_bits(a_stack);
	while (bits < max_bits)
	{
		nb = 0;
		while (nb++ < size_lst)
		{
			top = *a_stack;
			// if top->index pos[i] & 1 was == 1, then make revers A
			//if the bits was 1 so it will be equal
			if (((top->index >> bits) & 1) == 1)
				//rotate a
				ra(a_stack);
			else
				// else push it to b

				pb (a_stack, b_stack);
		}
		//while it's not empty push to a, thats mean if nums in bits 0
		while (list_size (*b_stack) != 0)
			pa (a_stack, b_stack);
		bits++;
	}
}
