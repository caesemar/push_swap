/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocasado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:04:36 by jocasado          #+#    #+#             */
/*   Updated: 2023/05/27 03:07:38 by jocasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	ft_error_check(char **a)
{
	int	i;
	int	j;
	int	sign;

	j = 0;
	i = 1;
	while (a[i])
	{
		sign = 1;
		while (a[i][j])
		{
			if (ft_digit_comparation(a, i, j, sign))
				j++;
			else
				ft_error2();
			if (a[i][j - 1] == '+' || a[i][j - 1] == '-' ||
						ft_isdigit(a[i][j - 1]))
				sign = 0;
			if (a[i][j - 1] == ' ')
				sign = 1;
		}
		j = 0;
		i++;
	}
}

char	*plus_on_input(char *temp1, int *status)
{
	if ((*temp1 == '-' && *(temp1 + 1) == '0') && *(temp1 + 2))
	{
		while ((*temp1 == '-' || *(temp1) == '0') && *(temp1 + 1))
		{
			temp1++;
			*status = *status + 1;
		}
		temp1--;
		*status = *status - 1;
		temp1[0] = '-';
	}
	while (*temp1 == '+' || (*temp1 == '-' && *(temp1 + 1) == '0'
			&& *(temp1 + 2) == 0)
		|| (*temp1 == '0' && *(temp1 + 1) != 0))
	{
		*status = *status + 1;
		temp1++;
	}
	return (temp1);
}

static int	ft_duplicate(char **argv, char *temp, int i, int j)
{
	char	**temp1;
	int		status;

	status = 0;
	while (argv[++i])
	{
		temp1 = ft_split(argv[i], ' ');
		if (!temp1)
			return (1);
		while (temp1[++j])
		{	
			temp1[j] = plus_on_input(temp1[j], &status);
			temp = ft_temp(temp);
			if (ft_strncmp(temp, temp1[j], ft_strlen(temp1[j])) == 0)
				return (duplicate_error(temp1, status, j, 0));
			while (status-- != 0)
				temp1[j]--;
			status = 0;
		}
		ft_free2d(temp1);
		j = -1;
	}
	return (0);
}

void	split_input(char **argv, t_lst **a, int i)
{
	char	**temp;
	int		j;
	int		error;

	error = 0;
	j = -1;
	while (argv[++i])
	{
		temp = ft_split(argv[i], ' ');
		if (!temp)
			return ;
		while (temp[++j])
		{
			error = ft_duplicate(argv, temp[j], i - 1, j);
			if (error == 1)
				break ;
			minusto0(temp[j]);
			add_to_end(ft_atoi(temp[j]), a);
		}
		j = -1;
		ft_free2d(temp);
		if (error == 1)
			ft_error(a);
	}
}

void	ft_input_checker(char **argv, t_lst **a)
{
	ft_error_check(argv);
	input_overflow(argv, 0, -1, 0);
	split_input(argv, a, 0);
	index_assign(a);
}
