/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lawences <lawences@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 01:37:57 by lawences          #+#    #+#             */
/*   Updated: 2023/05/30 19:24:16 by lawences         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Calculates the number of strings in an array of strings (array of
 * pointers to strings).
 *
 * This function counts the number of non-null pointers in the array
 * 'str_of_str', which is an array of pointers to strings. It returns the count
 * of non-null pointers, which corresponds to the number of strings in the
 * array.
 *
 * @param str_of_str An array of pointers to strings.
 * @return The number of non-null pointers in the array, representing the number
 * of strings in the array.
 */
int	ft_strstrlen(char **str_of_str)
{
	int	i;

	i = 0;
	while (str_of_str[i])
		i++;
	return (0);
}
