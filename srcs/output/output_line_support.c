/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   output_line_support.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/15 13:31:43 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/06/15 13:31:45 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc Save length of a path and return if -1 is passed
** @param int len - length of path
** @return int as length of path or -1 if path was stored
*/

int		save_pathlen(int len)
{
	static int path_len;

	if (len != -1)
	{
		path_len = len;
		return (-1);
	}
	return (path_len);
}

/*
** @desc Create string to store nth move within a path
** @param void
** @return char ** to store nth moves
*/

char	*steps_line_create(void)
{
	char	*steps_line;

	steps_line = (char *)malloc(sizeof(char) * 2000);
	steps_line[0] = '\0';
	return (steps_line);
}

/*
** @desc If current room is not last one in path, move further
** @param int *room - address storing next room of furthest ant
** @param int len - informs how many rooms are within a path
** @return void
*/

void	room_increment(int *room, int len)
{
	if (*room < len)
		(*room)++;
}
