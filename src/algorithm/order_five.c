#include "../../inc/push_swap.h"


static void	ft_to_stack_b_five(t_stack **stack_a, t_stack **stack_b, int num)
{
	if (ft_pos_of_index(*stack_a, num) == 5)
		ft_rra(stack_a, 0);
	else if (ft_pos_of_index(*stack_a, num) == 2)
		ft_sa(stack_a, 0);
	else if (ft_pos_of_index(*stack_a, num) == 3 || ft_pos_of_index(*stack_a, num) == 4)
	{
		if (ft_pos_of_index(*stack_a, num) == 3)
			ft_rra(stack_a, 0);
		ft_rra(stack_a, 0);
		ft_rra(stack_a, 0);
	}
	if (ft_pos_of_index(*stack_a, num) != 0)
	{
		t_stack *head;

		head = *stack_a;
		*stack_b = ft_create_new_node(num);
		*stack_a = head->next;
		write(1, "pb\n", 3);
		//ft_pb(stack_a, stack_b);
	}
}

void	ft_to_stack_b_four(t_stack **stack_a, t_stack **stack_b, int num)
{
	//ft_printindex(*stack_a, " A INDEX");
	//ft_reposition_stack(*stack_b);
	//ft_printpos(*stack_a, "POS A");
	if (ft_pos_of_index(*stack_a, num) == 2)
		ft_sa(stack_a, 0);
	else if (ft_pos_of_index(*stack_a, num) == 3)
	{
		ft_rra(stack_a, 0);
		ft_rra(stack_a, 0);
	}
	else if (ft_pos_of_index(*stack_a, num) == 4)
		ft_rra(stack_a, 0);

	// ft_printindex(*stack_a, " A INDEX");
	// ft_printindex(*stack_b, " B INDEX");
	if (ft_pos_of_index(*stack_a, num) != 0)
		ft_pb(stack_a, stack_b);
}

void	ft_order_four_or_five(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_listsize(*stack_a) == 4)
	{
		ft_to_stack_b_four(stack_a, stack_b, 1);
		ft_order_three(stack_a);
		ft_pa(stack_a, stack_b);
	}
	else
	{
		ft_to_stack_b_five(stack_a, stack_b, 1);
		ft_reposition_stack(*stack_a);
		ft_to_stack_b_four(stack_a, stack_b, 2);
		ft_reposition_stack(*stack_a);
		ft_order_three(stack_a);
		if (ft_is_sorted(*stack_b))
			ft_sa(stack_b, 0);
		ft_pa(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
	}
}