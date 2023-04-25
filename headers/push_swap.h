/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:41:49 by jocasado          #+#    #+#             */
/*   Updated: 2023/04/25 19:40:41 by jocasado         ###   ########.fr       */
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
int		duplicate_error(char **temp1, int status, int j);
void	ft_error(t_lst **stack_a);
//FORBIDDEN
void print_stack(t_lst *s);
//END
#endif
