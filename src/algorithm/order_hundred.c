/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_hundred.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:18:29 by jcheel-n          #+#    #+#             */
/*   Updated: 2023/05/18 00:38:53 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

//return int number that has the lowest cost//

void	ft_set_target(t_stack **stack_a, t_stack **stack_b)
{
	int		biggest;
	int		target;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_b = *stack_b;
	while (tmp_b)
	{
		tmp_a = *stack_a;
		biggest = INT_MAX;
		while (tmp_a)
		{
			if (tmp_a->index > tmp_b->index && tmp_a->index < biggest)
			{
				biggest = tmp_a->index;
				target = tmp_a->index;
			}
			tmp_a = tmp_a->next;
		}
		if (biggest == INT_MAX)
			tmp_b->i_target = ft_find_smallest(*stack_a);
		else
			tmp_b->i_target = target;
		tmp_b = tmp_b->next;
	}
}

void	ft_calculate_cost(t_stack *stack_a, t_stack *stack_b)
{
	int		size_a;
	int		size_b;
	t_stack	*tmp;
	t_stack	*target;

	size_a = ft_listsize(stack_a);
	size_b = ft_listsize(stack_b);
	tmp = stack_b;
	while (tmp)
	{	
		target = ft_find_index(stack_a, tmp->i_target);
		tmp->cost = tmp->pos;
		if (!(tmp->up))
			tmp->cost = size_b - tmp->pos;
		if (target->up)
			tmp->cost += target->pos;
		else
			tmp->cost += size_a - target->pos;
		tmp = tmp->next;
	}
	return ;
}

void	ft_move_up(t_stack **stack_a, t_stack **stack_b,
	t_stack **target, t_stack **cheapest)
{
	while (*stack_a != *target)
	{
		if ((*target)->up)
			ft_ra(stack_a, 0);
		else
			ft_rra(stack_a, 0);
		ft_reposition_stack(*stack_a);
	}
	while (*stack_b != *cheapest)
	{
		if ((*cheapest)->up)
			ft_rb(stack_b, 0);
		else
			ft_rrb(stack_b, 0);
		ft_reposition_stack(*stack_b);
	}
}

void	ft_move(t_data *data, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*target;
	t_stack	*cheapest;

	cheapest = ft_find_index(*stack_b, data->cheapest_index);
	target = ft_find_index(*stack_a, cheapest->i_target);
	if (cheapest->up == 1 && target->up == 1)
		while (*stack_a != target && *stack_b != cheapest)
			ft_rr(stack_a, stack_b);
	else if (cheapest->up == 0 && target->up == 0)
		while (*stack_a != target && *stack_b != cheapest)
			ft_rrr(stack_a, stack_b);
	ft_reposition_stack(*stack_a);
	ft_reposition_stack(*stack_b);
	ft_move_up(stack_a, stack_b, &target, &cheapest);
	ft_pa(stack_a, stack_b);
}

void	ft_order_hundred(t_stack *stack_a, t_stack *stack_b)
{
	int		size;
	t_data	data;

	data.max_index = ft_listsize(stack_a);
	size = ft_listsize(stack_a);
	ft_pa(&stack_a, &stack_b);
	while (size-- > 3)
		ft_pb(&stack_a, &stack_b);
	ft_order_three(&stack_a, 0);
	while (stack_b)
	{
		ft_reposition_stack(stack_a);
		ft_reposition_stack(stack_b);
		ft_set_target(&stack_a, &stack_b);
		ft_calculate_cost(stack_a, stack_b);
		data.cheapest_index = ft_find_smallest_cost_int(stack_b);
		ft_move(&data, &stack_a, &stack_b);
	}
	ft_reposition_stack(stack_a);
	ft_move_to_top(&stack_a, 1);
	ft_delete_stack(&stack_a);
	return ;
}
