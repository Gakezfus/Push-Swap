/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_arr_dup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Elkan Choo <echoo@42mail.sutd.edu.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:24:17 by Elkan Choo        #+#    #+#             */
/*   Updated: 2025/12/26 18:18:59 by Elkan Choo       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

int	*ft_int_arr_dup(const int *i, size_t src_len, size_t dst_len)
{
	int		*dup;
	size_t	index;

	dup = malloc(dst_len);
	index = 0;
	while (index < src_len)
	{
		dup[index] = i[index];
		index++;
	}
	return (dup);
}
