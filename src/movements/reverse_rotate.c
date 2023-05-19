/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:18:39 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/05/18 23:48:52 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_rra(t_stack **stack_a, int print)
{
	t_stack	*temp_one;
	t_stack	*temp_two;
	t_stack	**rotate;

	if (!(*stack_a))
		return ;
	rotate = stack_a;
	temp_two = *rotate;
	temp_one = *stack_a;
	if (!temp_one->next)
		return ;
	while (temp_one->next)
		temp_one = temp_one->next;
	while (temp_two->next != temp_one)
		temp_two = temp_two->next;
	temp_two->next = NULL;
	temp_one->next = *stack_a;
	*stack_a = temp_one;
	if (print)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **stack_b, int print)
{
	t_stack	*temp_one;
	t_stack	*temp_two;
	t_stack	**rotate;

	if (!(*stack_b))
		return ;
	rotate = stack_b;
	temp_two = *rotate;
	temp_one = *stack_b;
	if (!temp_one->next)
		return ;
	while (temp_one->next)
		temp_one = temp_one->next;
	while (temp_two->next != temp_one)
		temp_two = temp_two->next;
	temp_two->next = NULL;
	temp_one->next = *stack_b;
	*stack_b = temp_one;
	if (print)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	ft_rra(stack_a, 0);
	ft_rrb(stack_b, 0);
	if (print)
		write(1, "rrr\n", 4);
}
