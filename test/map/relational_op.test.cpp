/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relational_op.test.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:55:11 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/26 11:35:25 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.test.hpp"

void	relation_op( void )
{
	std::cout << "test relation_op :" << std::endl;
	std::cout << std::endl;
	int	i = 0;
	pl::map<int, char>	foo, bar;

	relation(foo, bar, i);

	foo[42] = 'b';
	relation(foo, bar, i);

	bar[42] = 'c';
	relation(foo, bar, i);

	std::cout << "------------------------------------------" << std::endl;
}
