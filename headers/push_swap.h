/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:41:49 by jocasado          #+#    #+#             */
/*   Updated: 2023/05/16 21:12:56 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft_42/libft.h"

typedef struct s_lst
{
	int				content;
	int				index;
	struct s_lst	*next;
}	t_lst;

void	ft_input_checker(char **argv, t_lst **a, t_lst *new_node);
void	ft_free2d(char	**tofree);
t_lst	*create_node(int content);
void	add_to_end(int value, t_lst **s);
void	free_stack(t_lst **stack);
int		duplicate_error(char **temp1, int status, int j, int liberar);
void	ft_error(t_lst **stack_a);
void	ft_error2(void);
char	*ft_temp(char *temp1);
int		ft_digit_comparation(char **a, int i, int j, int sign);
void	minusto0(char *temp);
void	input_overflow(char **argv, int i, int j, int error);
void	index_assign(t_lst **a);
char	*plus_on_input(char *temp1, int *status);
void	swap(t_lst **a);
void	reverse_rotate(t_lst **a);
void	rotate(t_lst **a);
void	push(t_lst **a, t_lst **b);
void	print_ra(t_lst **a);
void	print_rra(t_lst **a);
void	print_sa(t_lst **a);
void	print_pa(t_lst **a, t_lst **b);
int		min_index(t_lst **a);
int		max_index(t_lst **a);
void	three_elem(t_lst **a);
int		stack_size(t_lst **a);
void	print_pb(t_lst **a, t_lst **b);
int		sorted(t_lst **a);
void	less_than_ten_elem(t_lst **a, t_lst **b);
//FORBIDDEN
void print_stack(t_lst *s);
//END
#endif
