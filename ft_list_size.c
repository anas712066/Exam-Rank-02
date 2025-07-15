#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	size = 0;

	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

#include <stdio.h>

int	main(void)
{
	t_list	node3 = {NULL, "Third"};
	t_list	node2 = {&node3, "Second"};
	t_list	node1 = {&node2, "First"};
	printf("Test Case 1: List size = %d\n", ft_list_size(&node1));
	
	t_list	*empty_list = NULL;
	printf("Test Case 2: List size = %d\n", ft_list_size(empty_list));
	
	t_list	single_node = {NULL, "Only one"};
	printf("Test Case 3: List size = %d\n", ft_list_size(&single_node));
	return (0);
}