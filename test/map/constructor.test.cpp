/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.test.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:52:33 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/25 11:18:32 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.test.hpp"

void	constructor( void )
{
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;

	pl::map<char, int>	first;								// empty
	first['a'] = 10;
	first['b'] = 20;
	first['c'] = 30;
	first['d'] = 42;
	printMap(first, "first");

	pl::map<char, int>	second(first.begin(),first.end());	// iterator
	printMap(second, "second");

	pl::map<char, int>	third(second);						// cpy
	printMap(third, "third");

	pl::map<char, int, comp>	fourth;						// empty with comp
	fourth['a'] = 10;
	fourth['b'] = 20;
	fourth['c'] = 30;
	fourth['d'] = 42;
	printMap(fourth, "fourth");

	pl::map<char, int, comp>	five = fourth;				// operator=
	printMap(five, "five");

	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}
