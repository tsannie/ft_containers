/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.test.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:52:33 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/26 11:55:08 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.test.hpp"

void	constructor( void )
{
	std::cout << "test constructor :" << std::endl;
	std::cout << std::endl;

	pl::set<int>	first;								// empty
	first.insert(10);
	first.insert(20);
	first.insert(30);
	first.insert(42);
	first.insert(50);
	printSet(first, "first");

	pl::set<int>	second(first.begin(),first.end());	// iterator
	printSet(second, "second");

	pl::set<int>	third(second);						// cpy
	printSet(third, "third");

	pl::set<int, comp>	fourth;							// empty with comp
	fourth.insert(10);
	fourth.insert(20);
	fourth.insert(30);
	fourth.insert(42);
	fourth.insert(50);
	printSet(fourth, "fourth");

	pl::set<int, comp>	five = fourth;					// operator=
	printSet(five, "five");

	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}
