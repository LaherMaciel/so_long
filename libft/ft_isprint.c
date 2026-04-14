/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lawences <lawences@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:28:42 by lawences          #+#    #+#             */
/*   Updated: 2022/11/02 18:32:08 by lawences         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks if a given integer represents a printable ASCII character.
 *
 * This function determines whether the provided integer 'a' represents a
 * printable ASCII character, which includes characters with ASCII values
 * ranging from 32 to 126 (inclusive). These characters are typically visible
 * and can be displayed on the screen.
 *
 * @param a The integer value to be checked.
 * @return 1 if 'a' is a printable ASCII character, 0 otherwise.
 */
int	ft_isprint(int a)
{
	if (a >= 32 && a <= 126)
		return (1);
	return (0);
}
