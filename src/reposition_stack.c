#include "../inc/push_swap.h"

void	ft_reposition_stack(t_stack *head)
{
	t_stack *temp;
	int i;
	int median;

	i = 1;
	temp = head;
	median = ft_listsize(head)/2;
	while (temp)
	{
		temp->pos = i;
		if (i <= median)
			temp->up = 1;
		else
			temp->up = 0;
		temp = temp->next;
		i++;
	}
}