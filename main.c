/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osallak <osallak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:47:05 by osallak           #+#    #+#             */
/*   Updated: 2022/01/19 16:00:10 by osallak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<libc.h>
#include<stdbool.h>

bool	ft_isdigit(char	*s)
{
	int	i;

	if (!*s)
		return (false);
	i = -1;
	while (s[++i])
		if (s[i] < 48 || s[i] > 57)
			return (false);
	return (s[i] ? false : true);
}

int	main(void)
{
	char	*input;
	int		number;

	scanf("%[^\n]",input);
	printf(ft_isdigit(input) ? "True" : "False");
	return (0);
}
