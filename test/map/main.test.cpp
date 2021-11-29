/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:32:43 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/29 08:46:17 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.test.hpp"
#include <ctime>

bool isFt(ft::vector<int> x)
{
	static_cast<void>(x);
	return true;
}

bool isFt(std::vector<int> x)
{
	static_cast<void>(x);
	return false;
}

int	main( void )
{
	clock_t		t;
	t = clock();

	constructor();
	all_it();
	capacity_test();
	element_access();
	modifiers();
	observers();
	operations();
	relation_op();

	t = clock() - t;
	pl::vector<int> type;
	std::cerr << (isFt(type) ? "ft::" : "std::")
		<<  "time for all test: [\033[1;36m"
		<< (static_cast<double>(t) / CLOCKS_PER_SEC)
		<< "s\033[0m]" << std::endl;
}
