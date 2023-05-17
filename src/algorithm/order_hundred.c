#include "../../inc/push_swap.h"

int	ft_find_smallest(t_stack *stack) 
{
	int smallest;
	t_stack	*tmp;

	smallest = INT_MAX;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index < smallest)
			smallest = tmp->index;
		tmp = tmp->next; 
	}
	return (smallest);
}

int	ft_find_biggest(t_stack *stack) 
{
	int biggest;
	t_stack	*tmp;

	biggest = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index > biggest)
			biggest = tmp->index;
		tmp = tmp->next;
	}
	return (biggest);
}

//return int number that has the lowest cost//

int	ft_find_smallest_cost_int(t_stack *stack) 
{
	int smallest;
	t_stack	*tmp;

	smallest = INT_MAX;
	tmp = stack;
	while (tmp)
	{
		if (tmp->cost < smallest)
		{
			smallest = tmp->cost;
		}
		tmp = tmp->next; 
	}
	tmp = stack;
	while (tmp)
	{
		if (smallest == tmp->cost)
		{
			break ;
		}
		tmp = tmp->next; 
	}
	return (tmp->index);
}

void	ft_set_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp_a;
	t_stack *tmp_b;
	int biggest;
	int target;

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
	int size_a;
	int size_b;
	
	t_stack *tmp;
	t_stack *target;
	
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

void	ft_cheapest(t_data *data, t_stack **stack_b)
{
	int		cheapest_index;
	
	
	cheapest_index = ft_find_smallest_cost_int(*stack_b);
	data->cheapest_index = cheapest_index;
	// if (cheapest_index == 92)//cheapest_index >= 92 && cheapest_index <= 95)
	// {	ft_printindex(*stack_a, "STACK A");
	// 	ft_printindex(*stack_b, "STACK B");
	// }
	return ;
}

void	ft_move(t_data *data, t_stack **stack_a, t_stack **stack_b)
{
	t_stack *cheapest;
	t_stack	*target;
	cheapest = ft_find_index(*stack_b, data->cheapest_index);
	target = ft_find_index(*stack_a, cheapest->i_target);
	if (cheapest->up == 1 && target->up == 1)
	{
		while (*stack_a != target && *stack_b != cheapest)
			ft_rr(stack_a, stack_b);
		ft_reposition_stack(*stack_a);
		ft_reposition_stack(*stack_b);
	}
	else if(cheapest->up == 0 && target->up == 0)
	{
		while (*stack_a != target && *stack_b != cheapest)
			ft_rrr(stack_a, stack_b);
		ft_reposition_stack(*stack_a);
		ft_reposition_stack(*stack_b);
	}
	while (*stack_a != target)
	{
		if (target->up)
			ft_ra(stack_a, 0);
		else
			ft_rra(stack_a, 0);
		ft_reposition_stack(*stack_a);
	}
	while (*stack_b != cheapest)
	{
		if (cheapest->up)
			ft_rb(stack_b, 0);
		else
			ft_rrb(stack_b, 0);
		ft_reposition_stack(*stack_b);
	}
	ft_pa(stack_a, stack_b);
}

void	ft_order_hundred(t_stack *stack_a, t_stack *stack_b)
{
	t_data data;
	t_stack	*tmp;
	int size;
	
	data.max_index = ft_listsize(stack_a);
	data.size_a = ft_listsize(stack_a);
	size = data.size_a;
	ft_pa(&stack_a, &stack_b);
	while (size-- > 3)
		ft_pb(&stack_a, &stack_b);
	ft_order_three(&stack_a);
	// ft_printindex(stack_a, "STACK A");
	// return ;
	while (stack_b)
	{
		ft_reposition_stack(stack_a);
		ft_reposition_stack(stack_b);
		ft_set_target(&stack_a, &stack_b); 
		ft_calculate_cost(stack_a, stack_b);	
		ft_cheapest(&data, &stack_b);
		ft_move(&data, &stack_a, &stack_b);
	}
	ft_reposition_stack(stack_a);
	tmp = ft_find_index(stack_a, 1);
	if (tmp->up)
		while (stack_a != tmp)
			ft_ra(&stack_a, 0);
	else
		while (stack_a != tmp)
			ft_rra(&stack_a, 0);

		// ft_printindex(stack_a, "STACK A");
		// ft_printlist(stack_a, "STACK A");
		// ft_printlist(stack_b, "STACK B");
	tmp = stack_a;
	while (stack_a)
	{
		tmp = stack_a->next;
		// ft_bzero(stack_a, sizeof(t_stack));
		free(stack_a);
		stack_a = tmp;
	}
	return ;
}


// tmp = stack_b;
		// printf("---------------TARGETS--------------");
		// while (tmp)
		// {	
		// 	// printf("INDEX %d COST %d  \n", tmp->index, tmp->cost);
		// 	// printf("TARGET %d \n", tmp->i_target);
		// // 	// printf("COST A %d COST B %d\n", tmp->cost_a, tmp->cost_b);
		// 	tmp = tmp->next;
		// }