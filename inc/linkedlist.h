
#ifndef LINKEDLIST_H
# define LINKEDLIST_H

typedef struct stack
{
	int				value;
	int				pos;
	int				index;
	int				cost;
	int				cost_a;
	int				cost_b;
	int				i_target;
	int				up;
	struct stack	*target;
	struct stack	*next;
	struct stack	*prev;
}t_stack;

void	ft_printlist(t_stack *head, char *id);
void	ft_printpos(t_stack *head, char *id);
void	ft_printindex(t_stack *head, char *id);

t_stack	*ft_create_new_node(int value);
t_stack	*ft_insert_at_head(t_stack **head, t_stack *node_to_insert);
t_stack *ft_insert_at_end(t_stack **head, t_stack *node_to_insert);
void	ft_insert_after_node(t_stack *node_to_insert_after, t_stack *newnode);
t_stack	*ft_find_node(t_stack *head, int value);
t_stack *ft_find_index(t_stack *head, int index);
t_stack *ft_find_pos(t_stack *head, int pos);
int		ft_pos_of_index(t_stack *head, int value);
int		ft_listsize(t_stack *head);
t_stack	*ft_find_smallest_cost(t_stack *head);
int		ft_find_biggest(t_stack *stack);

#endif