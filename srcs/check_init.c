/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aledru <aledru@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:54:25 by aledru            #+#    #+#             */
/*   Updated: 2018/04/04 19:54:27 by aledru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		present_block_init(int line, int col, int grid[9][9])
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
			if (j != col && i != line)
				if (grid[i][j] == grid[line][col])
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

int		present_line_init(int line, int col, int grid[9][9])
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (i != col)
		{
			if (grid[line][i] == grid[line][col])
				return (1);
		}
		i++;
	}
	return (0);
}

int		present_col_init(int line, int col, int grid[9][9])
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (i != line)
		{
			if (grid[i][col] == grid[line][col])
				return (1);
		}
		i++;
	}
	return (0);
}
