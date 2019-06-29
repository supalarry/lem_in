/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   best_combination_2.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/19 14:33:04 by fblom         #+#    #+#                 */
/*   Updated: 2019/06/19 14:33:04 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

void				make_combination_paths(t_combo *combination, int r)
{
	if (combination->paths)
		free(combination->paths);
	combination->paths = malloc(sizeof(int) * r + 1);
	combination->combo_size = r;
}
