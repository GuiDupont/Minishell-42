/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 15:50:31 by gdupont           #+#    #+#             */
/*   Updated: 2020/07/29 15:53:39 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		ft_putchar('-');
		ft_putstr(split[i]);
		ft_putstr("-\n");
		i++;
	}
}
