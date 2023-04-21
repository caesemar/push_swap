/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:47:07 by jocasado          #+#    #+#             */
/*   Updated: 2023/04/21 03:19:04 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		i;
	int		num_elem;

	i = 0;
	num_elem = 0;
	if (argc == 1)
		return (0);
	ft_input_checker(argv, &num_elem);
	return (0);
}
