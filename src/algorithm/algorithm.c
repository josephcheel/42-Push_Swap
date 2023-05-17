#include "../../inc/push_swap.h"

void	ft_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_listsize(*stack_a);
	
	ft_reposition_stack(*stack_a);
	ft_indexation(*stack_a);
	//ft_printindex(*stack_a, "INDEX");
	if (size == 2)
		ft_order_two(stack_a);
	else if (size == 3)
		ft_order_three(stack_a);
	else if (size == 4 || size == 5)
		ft_order_four_or_five(stack_a, stack_b);
	else if (size >= 6)
		ft_order_hundred(*stack_a, *stack_b);
	// else if (size <= 500)
	// 	ft_order_five_hundred(stack_a, stack_b);
	//ft_printlist(*stack_a, "algorithm inputff");
	//write(1, "OK\n", 3);

}