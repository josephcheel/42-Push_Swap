/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:18:19 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/05/18 23:52:57 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_order_five(t_stack **stack_a, t_stack **stack_b)
{
	int		biggest;

	while (ft_listsize(*stack_a) > 3)
	{
		biggest = ft_find_smallest(*stack_a);
		ft_move_to_top(stack_a, biggest);
		ft_pb(stack_a, stack_b, 1);
	}
	if (ft_is_sorted(*stack_b))
		ft_sa(stack_b, 1);
	ft_order_three(stack_a, 0);
	ft_pa(stack_a, stack_b, 1);
	ft_pa(stack_a, stack_b, 1);
	ft_delete_stack(stack_a);
}
