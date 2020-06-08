/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frchaban <frchaban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 13:33:23 by frchaban          #+#    #+#             */
/*   Updated: 2020/06/08 13:33:26 by frchaban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

int		ft_count_split(char **split)
{
	int i;

	i = 0;
	if (split == NULL)
		return (0);
	while(split[i] != NULL)
		i++;
	return (i);
}
