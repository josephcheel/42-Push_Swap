/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:18:42 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/05/19 00:37:56 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_sa(t_stack **stack_a, int print)
{
	t_stack	*tmp;

	if (!(*stack_a && (*stack_a)->next))
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = tmp->next;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	if (print)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack **stack_b, int print)
{
	t_stack	*tmp;

	if (!(*stack_b && (*stack_b)->next))
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = tmp->next;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
	if (print)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	ft_sa(stack_a, 0);
	ft_sb(stack_b, 0);
	if (print)
		write(1, "ss\n", 3);
}
