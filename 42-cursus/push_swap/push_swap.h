/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dverdini <dverdini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:48:46 by dverdini          #+#    #+#             */
/*   Updated: 2026/04/14 12:48:02 by dverdini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>

# define ON 1
# define OFF 0

/*
** -------------------- double linked list structure ---------------------------
*/
typedef struct s_dlist
{
	void			*content;
	int				val;
	int				index;
	int				pos;
	bool			median_up;
	int				best_move_count;
	bool			convenient;
	struct s_dlist	*target;
	struct s_dlist	*next;	
	struct s_dlist	*prev;
}	t_dlist;

t_dlist	*ft_dlstnew(void *content);
t_dlist	*ft_dlstlast(t_dlist *dlst);
void	ft_dlstdelone(t_dlist *dlst, void (*del)(void *));
void	ft_dlstclear(t_dlist **dlst, void (*del)(void *));
void	ft_dlstadd_back(t_dlist **dlst, t_dlist *new);
void	ft_dlstadd_front(t_dlist **dlst, t_dlist *new);
int		ft_lstsize(t_dlist *lst);

/*
** ---------------- push swap functions ----------------------------------------
*/
void	ps_parse_and_fill_stack(t_dlist **stack_a, char **str_values);

/*
** ---------------- push swap functions - parsing utils ------------------------
*/
t_dlist	*ps_create_node(int val);
int		ps_str_values_has_duplicates(t_dlist *stack_a, int val);
int		ps_is_str_val_valid(char *str_val);

/*
** ---------------- push swap functions - free memory and error utils ----------
*/

void	ps_error(t_dlist **stack_a, char **str_values);
void	ps_free_str_values(char **str_values);
void	ps_free_stack(t_dlist **stack_a);

/*
** ---------------- push swap functions - index algorithm / check is sorted ----
*/
void	ps_set_stack_index(t_dlist *stack_a);
int		ps_is_sorted(t_dlist *stack);
char	**ps_init_str_values(int argc, char **argv);
/*
** ---------------- ALGORITHM ARBITRAGE - algo ---------------------------------
*/
void	ps_arbitrage_algo(t_dlist **stack_a, t_dlist **stack_b);
void	ps_rotation_final(t_dlist **stack);

/*
** ---------------- ALGORITHM ARBITRAGE - settings -----------------------------
*/
void	set_pos_elem(t_dlist *stack);
void	set_target_a(t_dlist *stack_a, t_dlist *stack_b);
void	set_target_b(t_dlist *stack_b, t_dlist *stack_a);
void	set_move_best_count(t_dlist *a, t_dlist *b);
void	set_convenient(t_dlist *stack_a);

/*
** ---------------- ALGORITHM ARBITRAGE - moves --------------------------------
*/
void	rotate_both__up_or_down(t_dlist **a, t_dlist **b, t_dlist *c);
void	finish_rotation_a(t_dlist **a, t_dlist *c);
void	finish_rotation_b(t_dlist **b, t_dlist *c);
void	move_a_to_b(t_dlist **a, t_dlist **b);
void	move_b_to_a(t_dlist **b, t_dlist **a);
//void	rotate_both_up(t_dlist **a, t_dlist **b, t_dlist *c);
//void	rotate_both_down(t_dlist **a, t_dlist **b, t_dlist *c);

/*
** ---------------- ALGORITHM ARBITRAGE - utils --------------------------------
*/
void	ps_prepare_nodes(t_dlist *stack_a, t_dlist *stack_b);
int		ft_max(int nbr1, int nbr2);
t_dlist	*point_to_max(t_dlist *stack);
t_dlist	*point_to_min(t_dlist *stack);
t_dlist	*get_convenient(t_dlist *stack_a);

//OPERATIONS
/*
** ---------------- ALGORITHM ARBITRAGE - operations ---------------------------
*/
void	pa(t_dlist **stack_dst, t_dlist **stack_src, int relay);
void	pb(t_dlist **stack_dst, t_dlist **stack_src, int relay);
void	sa(t_dlist **stack_a, int relay);
void	sb(t_dlist **stack_b, int relay);
void	ss(t_dlist **stack_a, t_dlist **stack_b, int relay);
void	ra(t_dlist **stack_a, int relay);
void	rb(t_dlist **stack_b, int relay);
void	rr(t_dlist **stack_a, t_dlist **stack_b, int relay);
void	rra(t_dlist **stack_a, int relay);
void	rrb(t_dlist **stack_b, int relay);
void	rrr(t_dlist **stack_a, t_dlist **stack_b, int relay);

/*
** ---------------- CHECKER -------- ---------------------------
*/

#endif
