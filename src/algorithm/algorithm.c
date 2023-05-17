/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:18:15 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/05/18 00:42:05 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_listsize(*stack_a);
	ft_reposition_stack(*stack_a);
	ft_indexation(*stack_a);
	if (size == 2)
		ft_order_two(stack_a);
	else if (size == 3)
		ft_order_three(stack_a, 1);
	else if (size == 5)
		ft_order_five(stack_a, stack_b);
	else if (size >= 6 || size == 4)
		ft_order_hundred(*stack_a, *stack_b);
}
