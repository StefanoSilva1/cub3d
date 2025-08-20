/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdavi-al <sdavi-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:03:34 by sdavi-al          #+#    #+#             */
/*   Updated: 2025/08/20 13:27:05 by sdavi-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_format(char *str)

{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	if (len > 4 && str[len - 4] == '.' && str[len - 3] == 'c' \
	&& str[len - 2] == 'u' && str[len - 1] == 'b')
		return (1);
	return (0);
}
