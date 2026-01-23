/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salman <salman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 08:21:09 by alamjada          #+#    #+#             */
/*   Updated: 2025/12/30 11:31:56 by salman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_print_nbr_u(unsigned int nb)
{
	char	*res;
	int		len;

	res = ft_itoa_u(nb);
	ft_putstr_fd(res, 1);
	len = ft_strlen(res);
	free(res);
	return (len);
}
