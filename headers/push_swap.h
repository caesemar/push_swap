/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:41:49 by jocasado          #+#    #+#             */
/*   Updated: 2023/04/22 05:38:16 by jocasado         ###   ########.fr       */
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

typedef struct s_stack
{
	t_lst			*first;
	struct s_stack	*next;
}	t_stack;

void	ft_input_checker(char **argv, t_stack **a, t_lst *new_node);
void	ft_free2d(char	**tofree);
t_lst	*create_node(int content);
void	ft_stackadd_back(t_stack **stack, t_stack *nw);
t_stack	*pop(t_stack *a);
t_stack	*push(t_stack *top_stack, t_lst *head);
t_stack	*add_to_end(int value, t_stack *s);
void	free_stack(t_stack *stack);
//FORBIDDEN
void print_stack(t_stack *s);
//END
#endif
