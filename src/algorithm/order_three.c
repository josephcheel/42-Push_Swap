#include "../../inc/push_swap.h"

void	ft_order_three(t_stack **head)
{
	int	biggest;
	
	biggest = ft_find_biggest(*head);
	if ((*head)->index == biggest)
		ft_ra(head, 0);
	else if ((*head)->next->index == biggest)
		ft_rra(head, 0);
	if ((*head)->index > (*head)->next->index)
		ft_sa(head, 0);
}

// void	ft_order_three_backwards(t_stack **head)
// {
// 	int	biggest;
	
// 	biggest = ft_find_biggest(*head);
// 	if ((*head)->index != biggest)
// 	{
// 		if ((*head)->index > (*head)->next->index) 
// 			ft_sa(head, 0);
// 		else if ()
// 	}
// 	if ((*head)->index > (*head)->next->index && ) 
// 	// 	ft_rra(head, 0);
// 	// else 
// 		ft_ra(head, 0);
// 	if ((*head)->index < (*head)->next->index)
// 		ft_sa(head, 0);
// }