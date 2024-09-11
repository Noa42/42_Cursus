/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achacon- <achacon-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:06:14 by achacon-          #+#    #+#             */
/*   Updated: 2024/03/20 13:16:10 by achacon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				position;
	int				target;
	int				cost_a;
	int				cost_b;
	int				total_cost;
	struct s_list	*next;
}					t_stack;

//LIBFT
int					ft_isdigit(int c);
long				ft_atoi(const char *str);
void				ft_putstr_fd(char *s, int fd);

//START
int					start(int argc, char **argv, t_stack **stack_a);
t_stack				*take_arg(int argc, char **argv, int flag);
int					two_nodes_case(t_stack **stack_a);

//ERRORS
int					errors(int argc, char **argv);

//SORT THREE
void				keep_three_nodes(t_stack **stack_a, t_stack **stack_b);
t_stack				*order_a(t_stack *stack_a);

//SPLIT
char				**ft_split(char const *s, char c);

//UTILS
int					is_ordered(t_stack *head);
int					mean(t_stack *head);
int					array_len(char **s);
int					is_highest(int n, t_stack **stack);
char				**erase(char **array, int i);

//MANEJO STACKS
t_stack				*ft_stack_new(int value);
int					ft_stack_size(t_stack *head);
void				ft_stack_add_back(t_stack **head, t_stack *new);
t_stack				*ft_stack_last(t_stack *head);
int					clear_stack(t_stack **stack);

//SET UP FIELDS
void				set_targets(t_stack **stack_a, t_stack **stack_b, int max);
void				set_costs(t_stack **stack_a, t_stack **stack_b);
void				set_positions(t_stack **head);

//ALGORITHM
t_stack				*lowest_cost(t_stack *head);
int					lowest_node(t_stack *stack_a);
void				movement(t_stack **stack_a, t_stack **stack_b);
void				sort_and_push(t_stack **stack_a, t_stack **stack_b);
void				rotate_till_sorted(t_stack **stack_a);

//MOVE A
void				swap_a(t_stack **head);
void				push_a(t_stack **dest, t_stack **ori);
void				rotate_a(t_stack **head, int flag);
void				rev_rotate_a(t_stack **head, int flag);

//MOVE B
void				swap_b(t_stack **head);
void				push_b(t_stack **dest, t_stack **ori);
void				rotate_b(t_stack **head, int flag);
void				rev_rotate_b(t_stack **head, int flag);

#endif