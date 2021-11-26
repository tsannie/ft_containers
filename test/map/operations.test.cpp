/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.test.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:01:43 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/26 11:27:17 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.test.hpp"

void	find( void )
{
	std::cout << "test find :" << std::endl;
	std::cout << std::endl;
	pl::map<char,int>			mymap;
	pl::map<char,int>::iterator	it;

	mymap['a'] = 50;
	mymap['b'] = 100;
	mymap['c'] = 150;
	mymap['d'] = 200;

	mymap.erase(mymap.find('b'));

	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';

	std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}

void	count( void )
{
	std::cout << "test count :" << std::endl;
	std::cout << std::endl;
	pl::map<char,int>	mymap;

	mymap ['a'] = 101;
	mymap ['c'] = 202;
	mymap ['f'] = 303;

	std::cout << 'a' << (mymap.count('a') ? " is" : " is not")
		<< " an element of mymap." << std::endl;
	std::cout << 'b' << (mymap.count('b') ? " is" : " is not")
		<< " an element of mymap." << std::endl;
	std::cout << 'c' << (mymap.count('c') ? " is" : " is not")
		<< " an element of mymap." << std::endl;
	std::cout << 'd' << (mymap.count('d') ? " is" : " is not")
		<< " an element of mymap." << std::endl;

	std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}

void	lower_bound( void )
{
	std::cout << "test lower_bound :" << std::endl;
	std::cout << std::endl;
	pl::map<char,int>			mymap;
	pl::map<char,int>::iterator	it;

	mymap['a'] = 20;
	mymap['b'] = 40;
	mymap['c'] = 60;
	mymap['d'] = 80;
	mymap['e'] = 100;

	std::cout << "lower is b = " << (mymap.lower_bound('b'))->first
		<< std::endl;
	std::cout << "lower is d = " << (mymap.lower_bound('d'))->first
		<< std::endl;
	std::cout << "lower is e = " << (mymap.lower_bound('e'))->first
		<< std::endl;

	printMap(mymap,"mymap");

	std::cout << "------------------------------------------" << std::endl;
}

void	upper_bound( void )
{
	std::cout << "test upper_bound :" << std::endl;
	std::cout << std::endl;
	pl::map<char,int>			mymap;
	pl::map<char,int>::iterator	it;

	mymap['a'] = 20;
	mymap['b'] = 40;
	mymap['c'] = 60;
	mymap['d'] = 80;
	mymap['e'] = 100;

	std::cout << "upper is a = " << (mymap.upper_bound('a'))->first
		<< std::endl;
	std::cout << "upper is b = " << (mymap.upper_bound('b'))->first
		<< std::endl;
	std::cout << "upper is d = " << (mymap.upper_bound('d'))->first
		<< std::endl;

	printMap(mymap,"mymap");

	std::cout << "------------------------------------------" << std::endl;
}

void	equal_range( void )
{
	std::cout << "test equal_range :" << std::endl;
	std::cout << std::endl;
	pl::map<char,int>	mymap;
	pl::pair<pl::map<char,int>::iterator, pl::map<char,int>::iterator>	ret;

	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;
	mymap['d'] = 40;
	mymap['e'] = 50;

	ret = mymap.equal_range('a');
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
	std::cout << std::endl;

	ret = mymap.equal_range('b');
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
	std::cout << std::endl;

	ret = mymap.equal_range('d');
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << " => " << ret.first->second << '\n';
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << " => " << ret.second->second << '\n';
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
