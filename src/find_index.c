#include "../inc/push_swap.h"

static int	index(t_stack *head, int num)
{
	int	i;

	i = 0;
	while (head)
	{
		if (head->value <= num)
			i++;
		head = head->next;
	}
	return (i);
}

void	ft_indexation(t_stack *head)
{
	t_stack *temp;

	temp = head;
	while (temp)
	{
		temp->index = index(head, temp->value);
		temp = temp->next;
	}
}
