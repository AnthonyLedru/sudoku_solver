/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:54:12 by aledru            #+#    #+#             */
/*   Updated: 2018/04/04 19:54:15 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku_solver.h"

int		present_block(int digit, int line, int col, int grid[9][9])
{
	int i;
	int j;
	int k;
	int l;

	i = line - (line % 3);
	j = col - (col % 3);
	k = line - (line % 3);
	l = col - (col % 3);
	while (i < k + 3)
	{
		while (j < l + 3)
		{
			if (grid[i][j] == digit)
			{
				return (1);
			}
			j++;
		}
		j = l;
		i++;
	}
	return (0);
}

int		present_line(int digit, int line, int grid[9][9])
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (grid[line][i] == digit)
			return (1);
		i++;
	}
	return (0);
}

int		present_col(int digit, int col, int grid[9][9])
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (grid[i][col] == digit)
			return (1);
		i++;
	}
	return (0);
}
