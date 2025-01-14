/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valba-pa <valba-pa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:26:11 by valba-pa          #+#    #+#             */
/*   Updated: 2024/10/11 04:34:26 by valba-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp_ptr;

	tmp_ptr = (unsigned char *)b;
	while (len > 0)
	{
		*(tmp_ptr++) = (unsigned char)c;
		len--;
	}
	return (b);
}
