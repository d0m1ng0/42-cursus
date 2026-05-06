/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:23:08 by dverdini          #+#    #+#             */
/*   Updated: 2026/04/14 10:09:38 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	ps_set_stack_index(t_dlist *stack_a)
{
	int		index;
	t_dlist	*cur;
	t_dlist	*run;

	cur = stack_a;
	while (cur)
	{
		index = 0;
		run = stack_a;
		while (run)
		{
			if (*(int *)(run->content) < *(int *)(cur->content))
				index++;
			run = run->next;
		}
		cur->index = index;
		cur = cur->next;
	}
}

void	ps_sort_two(t_dlist **stack_a)
{
	if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
		sa(stack_a, ON);
}

int	main(int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;
	char	**str_values;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	str_values = ps_init_str_values(argc, argv);
	if (!str_values)
		return (1);
	ps_parse_and_fill_stack(&stack_a, str_values);
	ps_set_stack_index(stack_a);
	if (ps_is_sorted(stack_a))
	{
		ps_free_str_values(str_values);
		return (ps_free_stack(&stack_a), 0);
	}
	if (ft_lstsize(stack_a) == 2)
		ps_sort_two(&stack_a);
	else if (ft_lstsize(stack_a) >= 3)
		ps_arbitrage_algo(&stack_a, &stack_b);
	ps_free_str_values(str_values);
	ps_free_stack(&stack_a);
	return (0);
}
/*
//TEST DOUBLE LINKED LIST

int	main(void)
{
	int	*nbr1 = (int *)malloc(sizeof(int));
	int	*nbr2 = (int *)malloc(sizeof(int));
	int	*nbr3 = (int *)malloc(sizeof(int));
	t_dlist	*head;
	t_dlist	*n1;
	t_dlist	*n2;
	t_dlist	*n3;

	*nbr1 = 42;
	*nbr2 = 43;
	*nbr3 = 44;
	n1 = ft_dlstnew(nbr1);
	n2 = ft_dlstnew(nbr2);
	n3 = ft_dlstnew(nbr3);
	head = NULL;
	ft_dlstadd_back(&head, n1);
	ft_dlstadd_back(&head, n2);
	ft_dlstadd_back(&head, n3);
	if (n2->next == n3)
		ft_putstr_fd("Test OK: pointer \"next\" is correct!\n ", 1);
	ft_dlstclear(&head, &free);
	return (0);
}
*/
/*
LESSON

the goal is to order numbers passed to the program with strings.

To do that:

creation of double linked lists


the string argument must be parsed:
the element at this point is a array of strings

lancio ora la funzione per validare gli elementi stringa e popolare lo stack
qui devo fare una validazione di ogni elemento stringa


//NORMALIZING IN A STRING
//PARSING AND POPULATION AND ERRORS AND FREE
	//1. input validation and population
	ps_parse_and_fill_stack(&stack_a, str_values);
		//OK- before converting: string validation
		//OK - here we parse parse and create the stack or call ft_error
		//OK errors function if something is wrong
	//2. clean the str_values only if ft_split has been used
//	ps_free_str_values(str_values);
	//from now str_values does not exist anymore. Only stack_a
//CORE
	//3. check if the stack_a is already oredere and if yes return 1
//	ft_is_stack_sorted(&stack_a);
	//4. Turk algorithm
	ps_set_stack_index(stack_a);
//	ps_print_stack(stack_a, "string INITIALIZED");
	//TURK ALGORITHM: selective rooting
	//1 - push to stack_b keeping stack_b semiordered
	//2 - calculate cost for each a_node to take it in the right
	//3 - position in staack_b
	//4 - move to stack_b: deplace the node with minor cost
	//5 - final sort: when stack_a has only 3 elements they must be
	//ordered then every elements are moved from stack_b to stack_a
	//5. free memory ft_dlstclear
	//str_values = ft_split(argv[1], ' ');

*/
/*
	test
%ARG=$(seq -1000 1000 | shuf -n 500 | tr '\n' ' '); ./push_swap $ARG 
| ./checker_linux $ARG && ./push_swap $ARG | wc -l

*/
