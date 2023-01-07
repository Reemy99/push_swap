/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:06:53 by realdahh          #+#    #+#             */
/*   Updated: 2023/01/05 18:41:04 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_list(int nb)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->data = nb;
	new->index = -1;
	new->next = NULL;
	return (new);
}

t_node	*last_list(t_node *uper)
{
	t_node	*new;

	new = uper;
	while (new->next)
	{
		new = new->next;
		if (new->next == NULL)
			return (new);
	}
	return (new);
}

void	add_back_list(t_node **stack, t_node *new)
{
	t_node	*count;

	if (*stack)
	{
		count = last_list(*stack);
		count->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

int	list_size(t_node *top)
{
	size_t	i;
	t_node	*t;

	t = top;
	i = 0;
	while (t)
	{
		t = t->next;
		i++;
	}
	return (i);
}
