#include "../../inc/push_swap.h"

void	ft_order_two(t_stack **stack_a)
{
	if (!ft_is_sorted(*stack_a)) // nt necessary if is already ordered is catch in checker
		ft_sa(stack_a, 0);
}