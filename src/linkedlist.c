#include <stdio.h>
#include <stdlib.h>
//#include "../doublylist/doubly_linked_list.h"
#include "../inc/linkedlist.h"
#include "../inc/push_swap.h"

void	ft_printindex(t_stack *head, char *id)
{
	t_stack *temporary;
	temporary = head;
	printf("%s: ", id);
	while(temporary != NULL)
	{
		printf("%d - ",temporary->index);
		temporary = temporary->next;
	}
	printf("\n");
}

void	ft_printpos(t_stack *head, char *id)
{
	t_stack *temporary;
	temporary = head;
	printf("%s: ", id);
	while(temporary != NULL)
	{
		printf("%d - ",temporary->pos);
		temporary = temporary->next;
	}
	printf("\n");
}

void	ft_printlist(t_stack *head, char *id)
{
	t_stack *temporary;
	temporary = head;
	printf("%s: ", id);
	while(temporary != NULL)
	{
		printf("%d - ",temporary->value);
		temporary = temporary->next;
	}
	printf("\n");
}

t_stack	*ft_create_new_node(int value)
{
	t_stack *result;
	result = malloc(sizeof(t_stack));
	result->value = value;
	result->next = NULL;
	return result;
}

t_stack *ft_insert_at_head(t_stack **head, t_stack *node_to_insert)
{
	node_to_insert->next = *head;
	*head = node_to_insert;
	return node_to_insert;
}

t_stack *ft_insert_at_end(t_stack **head, t_stack *node_to_insert)
{
	t_stack	*temp;

	if (!head)
		return (node_to_insert);
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = node_to_insert;
	return *head;
}

void	ft_insert_after_node(t_stack *node_to_insert_after, t_stack *newnode)
{
	newnode->next = node_to_insert_after->next;
	node_to_insert_after->next = newnode;
}

t_stack *ft_find_node(t_stack *head, int value)
{
	t_stack *tmp;
	tmp = head;
	while(tmp != NULL)
	{
		if (tmp->value == value)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

// return t_stack pointing the index 
t_stack *ft_find_index(t_stack *head, int index)
{
	t_stack *tmp;
	tmp = head;
	while(tmp != NULL)
	{
		if (tmp->index == index)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

t_stack	*ft_find_smallest_cost(t_stack *head)
{
	t_stack *tmp;
	t_stack *smallest;

	tmp = head;
	smallest = head;
	while(tmp != NULL)
	{
		printf("%d\n", smallest->cost);
		if (tmp->cost < smallest->cost)
			smallest = tmp;
		tmp = tmp->next;
	}
	
	return (smallest);
}

t_stack *ft_find_pos(t_stack *head, int pos)
{
	t_stack *tmp;
	tmp = head;
	while(tmp != NULL)
	{
		if (tmp->pos == pos)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}


//return pos
int ft_pos_of_index(t_stack *head, int value)
{
	t_stack *tmp;
	
	tmp = head;
	while(tmp)
	{
		if (tmp->index == value)
			return tmp->pos;
		tmp = tmp->next;
	}
	return 0;
}

int	ft_listsize(t_stack *head)
{
	t_stack *temp;
	int len;

	len = 0;
	temp = head;
	while (temp)
	{
		
		temp = temp->next;
		len++;
	}
	return (len);
}


// int	main(void)
// {
// 	t_stack *head = NULL;
// 	t_stack *tmp;
	
// 	// tmp = create_new_node(1);
// 	// head = tmp;
// 	// tmp = create_new_node(2);
// 	// tmp->next = head;
// 	// head = tmp;
// 	// tmp = create_new_node(3);
// 	// tmp->next = head;
// 	// head = tmp;
// 	int i; 
// 	i = 0;
// 	while (i < 55)
// 	{
// 		tmp = create_new_node(i);
// 		insert_at_head(&head, tmp);
// 		i++;
// 	}

// 	tmp = find_node(head, 14);
// 	printf("Found node with %d\n", tmp->value);

// 	//insert_after_node(tmp, create_new_node(200));

// 	printlist(head);

// }