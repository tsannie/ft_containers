/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observers.test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:35:59 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/26 12:42:26 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.test.hpp"

void	key_comp( void )
{
	std::cout << "test key_comp :" << std::endl;
	std::cout << std::endl;

	pl::set<char>				myset;
	pl::set<char>::key_compare	mycomp = myset.key_comp();
	pl::set<char>::iterator		it;
	char						highest;

	myset.insert('a');
	myset.insert('b');
	myset.insert('c');
	myset.insert('d');
	myset.insert('e');
	myset.insert('f');

	std::cout << "myset contains: ";
	highest = *myset.rbegin();
	it = myset.begin();
	do {
		std::cout << *it << " ";
	} while ( mycomp(*(++it),highest) );
	std::cout << std::endl;

	std::cout << std::endl;

	pl::set<char, comp>					myset2;
	pl::set<char, comp>::key_compare	mycomp2 = myset2.key_comp();
	pl::set<char, comp>::iterator		it2;

	myset2.insert('a');
	myset2.insert('b');
	myset2.insert('c');
	myset2.insert('d');
	myset2.insert('e');
	myset2.insert('f');

	std::cout << "myset2 contains: ";
	highest = *myset2.rbegin();
	it2 = myset2.begin();
	do {
		std::cout << *it2 << " ";
	} while ( mycomp2(*(++it2),highest) );
	std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}

void	value_comp( void )
{
	std::cout << "test value_comp :" << std::endl;
	std::cout << std::endl;
	pl::set<char> myset;
	pl::set<char>::value_compare mycomp = myset.value_comp();

	myset.insert('a');
	myset.insert('b');
	myset.insert('c');
	myset.insert('d');
	myset.insert('e');
	myset.insert('f');

	std::cout << "myset contains: ";

	char highest = *myset.rbegin();
	pl::set<char>::iterator it = myset.begin();
	do {
		std::cout << *it << " ";
	} while ( mycomp(*(++it),highest) );
	std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}

void	observers( void )
{
	key_comp();
	value_comp();
}
