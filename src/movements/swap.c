#include "../../inc/push_swap.h"

void	ft_sa(t_stack **stack_a, int twice)
{
	// t_stack	*value_one;
	// t_stack	*value_two;
	t_stack *tmp;
	// int		swap;

	// value_one = *stack_a;
	// value_two = *stack_a;

	// if (!value_two->next)
	// 	return ;
	// value_two = value_two->next;
	// swap = value_two->value;
	// value_two->value = value_one->value;
	// value_one->value = swap;
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
	t_stack	*value_one;
	t_stack	*value_two;
	int		swap;

	value_one = *stack_b;
	value_two = *stack_b;

	if (!value_two->next)
		return ;
	value_two = value_two->next;
	swap = value_two->value;
	value_two->value = value_one->value;
	value_one->value = swap;
	if (!twice)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_sa(stack_a, 1);
	ft_sb(stack_b, 1);
	write(1, "ss\n", 3);
}
