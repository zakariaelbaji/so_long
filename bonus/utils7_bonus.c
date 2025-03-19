/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-baji <zel-baji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 00:26:30 by zel-baji          #+#    #+#             */
/*   Updated: 2025/03/18 03:09:04 by zel-baji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	validate_map_content(char *content)
{
	size_t	len;

	len = ft_strlen(content);
	if (len > 0 && content[len - 1] == '\n')
	{
		ft_print_error("Error: Map ends with empty line\n");
		free(content);
		exit(1);
	}
}
