/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oubelhaj <oubelhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 01:47:14 by oubelhaj          #+#    #+#             */
/*   Updated: 2023/11/15 14:24:53 by oubelhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	int	i = 0, j;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (++i < ac) {
		j = -1;
		while (av[i][++j])
			std::cout << (char)toupper(av[i][j]);
	}
	std::cout << std::endl;
	return (0);
}
