/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: realdahh <realdahh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:58:15 by realdahh          #+#    #+#             */
/*   Updated: 2023/01/07 12:04:39 by realdahh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
}				t_node;

/**
 * @brief 
 * 
 * @param nb 
 * @return int 
 */
typedef struct s_vars
{
	int		i;
	int		x;
	long	nb;
	t_node	*new;
	char	**arg;
}				t_vars;

//________LIBFT_________//
int		ft_isdigit(int nb);
long	ft_atoi(char *str);
void	put_char_fd(char c, int fd);
void	put_str_fd(char *str, int fd);
void	put_endl_fd(char *str, int fd);
char	**ft_split(char const *str, char c);

//________LISTS_________//
t_node	*new_list(int nb);
int		list_size(t_node *top);
t_node	*last_list(t_node *uper);
void	add_back_list(t_node **stack, t_node *new);

//________CALL MOVES____________//
int		sa(t_node **a_stack);
int		sb(t_node **b_stack);
int		ss(t_node **a_stack, t_node **b_stack);
int		pa(t_node **a_stack, t_node **b_stack);
int		pb(t_node **a_stack, t_node **b_stack);
int		ra(t_node **a_stack);
int		rb(t_node **b_stack);
int		rr(t_node **a_stack, t_node **b_stack);
int		rra(t_node **a_stack);
int		rrb(t_node **b_stack);
int		rrr(t_node **a_stack, t_node **b_stack);

//________sorting___________//
void	ft_sorting(t_node **a_stack, t_node **b_stack);
void	simple_sort(t_node **a_stack, t_node **b_stack);
void	sort_3nums(t_node **a_stack);
void	sort_3numbers(t_node **a_stack);
void	sort_4numbers(t_node **a_stack, t_node **b_stack);
void	sort_5numbers(t_node **a_stack, t_node **b_stack);
void	radix_sort(t_node **a_stack, t_node **b_stack);

//________MOVES___________//
int		swap(t_node **stack);
int		rotate(t_node **stack);
int		reverse_rotate(t_node **stack);
int		push(t_node **stack_dst, t_node **stack_src);

void	check_arg(char **av);
void	ft_error(char *str, char **new);
void	ft_index(t_node **stack);
void	ft_free(char **str);
void	free_stack(t_node **stack);
int		ft_sorted(t_node **stack);
int		find_minimum(t_node **stack, int value);
int		find_max_bits(t_node **stack);
int		find_distance(t_node **stack, int number);
t_node	*find_next_min(t_node **stack);

#endif