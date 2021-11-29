/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:29:11 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/29 08:50:26 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.test.hpp"

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
	methods();
	relation_op();

	t = clock() - t;
	pl::vector<int> type;
	std::cerr << (isFt(type) ? "ft::" : "std::")
		<<  "time for all test: [\033[1;36m"
		<< (static_cast<double>(t) / CLOCKS_PER_SEC)
		<< "s\033[0m]" << std::endl;
}
