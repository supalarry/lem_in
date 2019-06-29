/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_combinations.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/31 19:20:11 by fblom         #+#    #+#                 */
/*   Updated: 2019/05/31 19:20:12 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc
** @param
** @return
*/

static int				set_middle(int r)
{
	int					middle;

	if (r > 3)
		middle = r - 2;
	else
		middle = 0;
	return (middle);
}

/*
** @desc swap the int array holding possible combinations of paths
** @desc
** @param
** @return
*/

static void				swap_int_array(t_room **paths_array, int *int_array, \
										int r, int found_paths)
{
	int					i;
	t_combo				*combo;
	int					*cross_paths;
	int					middle;

	middle = set_middle(r);
	cross_paths = paths_array[found_paths - 1]->cross_paths;
	combo = save_combo(NULL);
	i = r - 2;
	if (int_array[middle] == combo->paths[middle + 1] - 1)
		int_array[middle]++;
	while (i >= middle)
	{
		if (int_array[i] < combo->paths[i + 1] - 1)
		{
			int_array[i]++;
			if (check_cross_paths(i, int_array, cross_paths))
				continue ;
			loop_through_ints(&i, r, int_array, combo);
			i = -1;
		}
		else
			i--;
	}
}

/*
** @desc
** @param
** @return
*/

void					initialise_int_array(int r, int *int_array, \
							int found_paths, t_combo *combination)
{
	if (r == 1)
		int_array[0] = 0;
	if (r != 1)
	{
		set_int_array(int_array, r);
		int_array[r - 1] = found_paths - 1;
		combination->paths[r - 1] = found_paths - 1;
	}
}

/*
** @desc
** @param
** @return
*/

static int				add_combinations(t_room **paths, int fp, int r)
{
	static t_combo		*combination;
	int					int_array[r];
	int					ret;
	int					middle;

	middle = set_middle(r);
	if (!combination)
		combination = (t_combo *)malloc(sizeof(t_combo));
	initialise_int_array(r, int_array, fp, combination);
	while (r == 1 || int_array[middle] < combination->paths[middle + 1])
	{
		ret = best_combination(int_array, paths, make_vars(r, fp), combination);
		if (ret == 1)
		{
			make_combination_paths(combination, r);
			edit_combo_array(combination, int_array, r);
			save_combo(combination);
			return (1);
		}
		if (ret == 2)
			return (0);
		swap_int_array(paths, int_array, r, fp);
	}
	return (0);
}

/*
** @desc increases r (combo size) every time a combination is found
** @param the array of all found paths, the number of found paths
** @return (0) if no bigger combination is possible
** @return (1) if more paths need to be found
*/

int						get_combinations(t_room **paths_array, int found_paths)
{
	static int			r;
	int					ret;
	int					max;

	if (!r)
		r = 1;
	ret = add_combinations(paths_array, found_paths, r);
	if (ret)
		r++;
	max = save_max(0);
	if (r > max)
		return (0);
	return (1);
}
