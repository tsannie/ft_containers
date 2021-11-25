/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:52:33 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/25 12:30:22 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.test.hpp"

void	empty( void )
{
	std::cout << "test empty :" << std::endl;
	std::cout << std::endl;

	pl::map<int, int> first;

	std::cout << "1st check :" << std::endl;
	std::cout << "empty : " << (first.empty() ? "true" : "false") << std::endl;
	std::cout << std::endl;

	for (int i = 0 ; i <= 42 ; ++i)
		first.insert( pl::pair<int, char>(i, i) );
	std::cout << "2nd check :" << std::endl;
	std::cout << "empty : " << (first.empty() ? "true" : "false") << std::endl;
	std::cout << std::endl;

	first.clear();
	std::cout << "4th check :" << std::endl;
	std::cout << "empty : " << (first.empty() ? "true" : "false") << std::endl;
	std::cout << std::endl;

	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void size( void )
{
	std::cout << "test size :" << std::endl;
	std::cout << std::endl;

	pl::map<int, int> myints;

	std::cout << "1st check :" << std::endl;
	printMap(myints, "myints");

	for (int i = 0 ; i < 100 ; ++i)
		myints.insert( pl::pair<int, int>(i, i * 7) );

	std::cout << "2nd check :" << std::endl;
	printMap(myints, "myints");

	myints.insert( pl::pair<int, int>(420, 21) );

	std::cout << "3rd check :" << std::endl;
	printMap(myints, "myints");

	for (int i = 0; i < 50; i++)
		myints.erase(i);

	std::cout << "4th check :" << std::endl;
	printMap(myints, "myints");

	for (int i = 50; i < 90; i++)
		myints.erase(i);

	std::cout << "5th check :" << std::endl;
	printMap(myints, "myints");
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void max_size( void )
{
	std::cout << "test max_size :" << std::endl;
	std::cout << std::endl;

	pl::map<int, int> first;

	std::cout << "max_size :" << first.max_size() << std::endl;

	for (int i = 0 ; i < 50 ; ++i)
		first.insert( pl::pair<int, int>(i * 6, i * 8) );

	std::cout << "max_size: " << first.max_size() << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	capacity_test( void )
{
	empty();
	size();
	max_size();
}

