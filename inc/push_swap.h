/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 00:51:06 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/05/19 00:36:16 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct stack
{
	int				up;
	int				pos;
	int				cost;
	int				index;
	int				value;
	int				i_target;
	struct stack	*target;
	struct stack	*next;
}t_stack;

typedef struct s_data
{
	int		cheapest_index;
	int		max_index;
}t_data;

//===================CHECKER=================//
void	ft_numarg(int ac, char **av);
void	ft_checker(t_stack *stack_a);
int		ft_is_sorted(t_stack *stack_a);
void	ft_is_doubled(t_stack *stack_a);
//===================MOVEMENTS=================//	

void	ft_sa(t_stack **stack_a, int print);
void	ft_sb(t_stack **stack_b, int print);
void	ft_ss(t_stack **stack_a, t_stack **stack_b, int print);

void	ft_pa(t_stack **stack_a, t_stack **stack_b, int print);
void	ft_pb(t_stack **stack_a, t_stack **stack_b, int print);

void	ft_ra(t_stack **stack_a, int print);
void	ft_rb(t_stack **stack_b, int print);
void	ft_rr(t_stack **stack_a, t_stack **stack_b, int print);

void	ft_rra(t_stack **stack_a, int print);
void	ft_rrb(t_stack **stack_b, int print);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int print);

//===================ALGORITHM=================//
void	ft_algorithm(t_stack **stack_a, t_stack **stack_b);
void	ft_order_two(t_stack **stack_a);
void	ft_order_three(t_stack **stack_a, int delete);
void	ft_order_five(t_stack **stack_a, t_stack **stack_b);
void	ft_order_hundred(t_stack *stack_a, t_stack *stack_b);

//===================UTILS=================//

void	ft_indexation(t_stack *head);
void	ft_delete_stack(t_stack **head);
void	ft_reposition_stack(t_stack *head);
void	ft_move_to_top(t_stack **head, int index_to_move);

t_stack	*ft_find_pos(t_stack *head, int pos);
t_stack	*ft_find_smallest_cost(t_stack *head);
t_stack	*ft_find_index(t_stack *head, int index);
int		ft_listsize(t_stack *head);
int		ft_find_biggest(t_stack *stack);
int		ft_find_smallest(t_stack *stack);
int		ft_find_smallest_cost_int(t_stack *stack);
int		ft_pos_of_index(t_stack *head, int value);

//===================CREATE_STACK=================//
t_stack	*ft_create_new_node(int value);
t_stack	*ft_create_stack(int ac, char **av);
t_stack	*ft_insert_at_head(t_stack **head, t_stack *node_to_insert);

#endif
