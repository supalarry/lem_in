/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   copy.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lskrauci <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 10:20:24 by lskrauci      #+#    #+#                 */
/*   Updated: 2019/06/17 10:20:25 by lskrauci      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_header.h"

char	*copy_input(char *line)
{
	char		*temp;
	static char	*copy;

	if (copy == NULL && line != NULL)
	{
		copy = ft_strdup(line);
		temp = copy;
		copy = ft_strjoin(copy, "\n");
		free(temp);
	}
	else if (copy != NULL && line != NULL)
	{
		temp = copy;
		copy = ft_strjoin(copy, line);
		free(temp);
		temp = copy;
		copy = ft_strjoin(copy, "\n");
		free(temp);
	}
	else
		return (copy);
	return (NULL);
}
