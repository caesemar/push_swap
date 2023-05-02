/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 09:30:32 by jocasado          #+#    #+#             */
/*   Updated: 2023/05/02 09:47:00 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	input_overflow(char **argv, int i, int j)
{
	char	**temp;
	int		error;
	char	*temp1;

	error = 0;
	while (argv[++i])
	{
		temp = ft_split(argv[i], ' ');
		while (temp[++j])
		{
			temp1 = ft_itoa(ft_atoi(temp[j]));
			if (ft_strncmp(temp1, temp[j], ft_strlen(temp[j])))
			{
				ft_putstr_fd("Input overflow, number over int\n", 2);
				free (temp1);
				error = 1;
				break ;
			}
			free (temp1);
		}
		j = -1;
		ft_free2d(temp);
	}
	if (error == 1)
		exit (1);
}
