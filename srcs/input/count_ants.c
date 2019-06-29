/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ants_count.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 16:15:01 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/05/23 16:15:02 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

/*
** @desc Check if user input was empty line or '0' ants
** @desc were entered or if non digit character exists.
** @param char *line - read input line
** @return 0 if line is empty, has 0 ants or has nondigit character
** @return 1 if opposite is true
*/

static int	validate_ants(char *line)
{
	int	i;

	i = 0;
	if (ft_strlen(line) == 0
	|| (ft_strlen(line) && line[0] == '0'))
	{
		ft_printf("ERROR\n");
		free(line);
		exit(1);
	}
	while (line[i] != '\0')
	{
		if (!ft_isdigit(line[i]))
		{
			ft_printf("ERROR\n");
			free(line);
			exit(1);
		}
		i++;
	}
	return (1);
}

/*
** @desc Read first input line and extract number of ants. Validate input
** @desc by checking if file is not empty and then skip all comments.
** @desc Then validate_ants function is called to further check input.
** @param void
** @return int as number of ants
** @return If it is empty file or error occured on reading, return -1
*/

int			count_ants(void)
{
	static int		ants;
	char			*line;
	int				ret;

	if (!ants)
	{
		ret = get_next_line(0, &line);
		if (ret == 0 || ret == -1)
			return (-1);
		while (ft_strlen(line) && line[0] == '#')
		{
			free(line);
			copy_input(line);
			ret = get_next_line(0, &line);
			if (ret == 0 || ret == -1)
				return (-1);
		}
		validate_ants(line);
		ants = ft_atoi(line);
		copy_input(line);
		free(line);
	}
	return (ants);
}
