/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:57:45 by jocasado          #+#    #+#             */
/*   Updated: 2023/05/15 19:47:21 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	print_ra(t_lst **a)
{
	ft_putstr_fd("ra\n", 1);
	rotate(a);
}

void	print_rb(t_lst **a)
{
	ft_putstr_fd("rb\n", 1);
	rotate(a);
}

void	print_rra(t_lst **a)
{
	ft_putstr_fd("rra\n", 1);
	reverse_rotate(a);
}

void	print_rrb(t_lst **a)
{
	ft_putstr_fd("rrb\n", 1);
	reverse_rotate(a);
}

void	print_sa(t_lst **a)
{
	ft_putstr_fd("sa\n", 1);
	swap(a);
}
