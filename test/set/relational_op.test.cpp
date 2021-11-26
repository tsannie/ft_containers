/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relational_op.test.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:55:11 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/26 12:52:11 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.test.hpp"

void	relation_op( void )
{
	std::cout << "test relation_op :" << std::endl;
	std::cout << std::endl;
	int	i = 0;
	pl::set<int>	foo, bar;

	relation(foo, bar, i);

	foo.insert(42);
	relation(foo, bar, i);

	foo.insert(42);
	bar.insert(42);
	bar.insert(50);
	relation(foo, bar, i);

	std::cout << "------------------------------------------" << std::endl;
}
