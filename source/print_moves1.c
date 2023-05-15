/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:14:24 by jocasado          #+#    #+#             */
/*   Updated: 2023/05/15 19:47:01 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	print_sb(t_lst **a)
{
	ft_putstr_fd("sb\n", 1);
	swap(a);
}

void	print_pa(t_lst **a, t_lst **b)
{
	ft_putstr_fd("pa\n", 1);
	push(b, a);
}

void	print_pb(t_lst **a, t_lst **b)
{
	ft_putstr_fd("pb\n", 1);
	push(a, b);
}
