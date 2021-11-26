/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.test.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:01:43 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/26 12:49:39 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.test.hpp"

void	find( void )
{
	std::cout << "test find :" << std::endl;
	std::cout << std::endl;
	pl::set<char>			myset;
	pl::set<char>::iterator	it;

	myset.insert('a');
	myset.insert('b');
	myset.insert('c');
	myset.insert('d');

	myset.erase(myset.find('b'));

	std::cout << "elements in myset:" << '\n';
	std::cout << "a => " << *myset.find('a') << '\n';
	std::cout << "c => " << *myset.find('c') << '\n';
	std::cout << "d => " << *myset.find('d') << '\n';

	std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}

void	count( void )
{
	std::cout << "test count :" << std::endl;
	std::cout << std::endl;
	pl::set<char>	myset;

	myset.insert('a');
	myset.insert('c');
	myset.insert('f');

	std::cout << 'a' << (myset.count('a') ? " is" : " is not")
		<< " an element of myset." << std::endl;
	std::cout << 'b' << (myset.count('b') ? " is" : " is not")
		<< " an element of myset." << std::endl;
	std::cout << 'c' << (myset.count('c') ? " is" : " is not")
		<< " an element of myset." << std::endl;
	std::cout << 'd' << (myset.count('d') ? " is" : " is not")
		<< " an element of myset." << std::endl;

	std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}

void	lower_bound( void )
{
	std::cout << "test lower_bound :" << std::endl;
	std::cout << std::endl;
	pl::set<char>			myset;
	pl::set<char>::iterator	it;

	myset.insert('a');
	myset.insert('b');
	myset.insert('c');
	myset.insert('d');
	myset.insert('e');

	std::cout << "lower is b = " << *(myset.lower_bound('b'))
		<< std::endl;
	std::cout << "lower is d = " << *(myset.lower_bound('d'))
		<< std::endl;
	std::cout << "lower is e = " << *(myset.lower_bound('e'))
		<< std::endl;

	printSet(myset,"myset");

	std::cout << "------------------------------------------" << std::endl;
}

void	upper_bound( void )
{
	std::cout << "test upper_bound :" << std::endl;
	std::cout << std::endl;
	pl::set<char>			myset;
	pl::set<char>::iterator	it;

	myset.insert('a');
	myset.insert('b');
	myset.insert('c');
	myset.insert('d');
	myset.insert('e');

	std::cout << "upper is a = " << *(myset.upper_bound('a'))
		<< std::endl;
	std::cout << "upper is b = " << *(myset.upper_bound('b'))
		<< std::endl;
	std::cout << "upper is d = " << *(myset.upper_bound('d'))
		<< std::endl;

	printSet(myset,"myset");

	std::cout << "------------------------------------------" << std::endl;
}

void	equal_range( void )
{
	std::cout << "test equal_range :" << std::endl;
	std::cout << std::endl;
	pl::set<char>	myset;
	pl::pair<pl::set<char>::iterator, pl::set<char>::iterator>	ret;

	myset.insert('a');
	myset.insert('b');
	myset.insert('c');
	myset.insert('d');
	myset.insert('e');

	ret = myset.equal_range('a');
	std::cout << "lower bound points to: ";
	std::cout << *ret.first << " => " << *ret.first << '\n';
	std::cout << "upper bound points to: ";
	std::cout << *ret.second << " => " << *ret.second << '\n';
	std::cout << std::endl;

	ret = myset.equal_range('b');
	std::cout << "lower bound points to: ";
	std::cout << *ret.first << " => " << *ret.first << '\n';
	std::cout << "upper bound points to: ";
	std::cout << *ret.second << " => " << *ret.second << '\n';
	std::cout << std::endl;

	ret = myset.equal_range('d');
	std::cout << "lower bound points to: ";
	std::cout << *ret.first << " => " << *ret.first << '\n';
	std::cout << "upper bound points to: ";
	std::cout << *ret.second << " => " << *ret.second << '\n';
	std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}

void	operations( void )
{
	find();
	count();
	lower_bound();
	upper_bound();
	equal_range();
}
