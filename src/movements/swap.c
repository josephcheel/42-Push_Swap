/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:18:42 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/05/17 18:27:04 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_sa(t_stack **stack_a, int twice)
{
	t_stack	*tmp;

	if (!(stack_a && (*stack_a)->next))
		return ;
	tmp = (*stack_a)->next;
	(*stack_a)->next = tmp->next;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	if (!twice)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack **stack_b, int twice)
{
	t_stack	*tmp;

	if (!(stack_b && (*stack_b)->next))
		return ;
	tmp = (*stack_b)->next;
	(*stack_b)->next = tmp->next;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
	if (!twice)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_sa(stack_a, 1);
	ft_sb(stack_b, 1);
	write(1, "ss\n", 3);
}
