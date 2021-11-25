/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:52:33 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/25 10:37:24 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.test.hpp"

void size( void )
{
	std::cout << "test size :" << std::endl;
	std::cout << std::endl;

	pl::vector<int> myints;

	std::cout << "1st check :" << std::endl;
	printVec(myints);

	for (int i = 0; i < 100; i++)
		myints.push_back(i * 6);

	std::cout << "2nd check :" << std::endl;
	printVec(myints);

	myints.insert(myints.end(), 10, 100);

	std::cout << "3rd check :" << std::endl;
	printVec(myints);

	for (int i = 0; i < 50; i++)
	myints.pop_back();

	std::cout << "4th check :" << std::endl;
	printVec(myints);

	for (int i = 0; i < 60; i++)
	myints.pop_back();

	std::cout << "5th check :" << std::endl;
	printVec(myints);
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void max_size( void )
{
	std::cout << "test max_size :" << std::endl;
	std::cout << std::endl;

	pl::vector<int> first;

	std::cout << "max_size :" << first.max_size() << std::endl;


	for (int i = 0; i < 500; i++)
		first.push_back(i * 6);

	std::cout << "max_size: " << first.max_size() << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void resize( void )
{
	std::cout << "test resize :" << std::endl;
	std::cout << std::endl;

	pl::vector<int> first;

	// set some initial content:
	for (int i = 0; i < 50 ; i++)
		first.push_back(i);

	std::cout << "1st check :" << std::endl;
	printVec(first);

	std::cout << "2nd check :" << std::endl;
	first.resize(5);
	printVec(first);

	std::cout << "3rd check :" << std::endl;
	first.resize(8, 100);
	printVec(first);

	std::cout << "4th check :" << std::endl;
	first.resize(70);
	printVec(first);

	first.resize(0, 0);
	std::cout << "5th check :" << std::endl;
	printVec(first);

	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	capacity( void )
{
	std::cout << "test capacity :" << std::endl;
	std::cout << std::endl;

	pl::vector<int> first;

	std::cout << "{ ";
	for (int i = 0; i < 550; i++)
	{
		if (!(i % 10))
			std::cout << first.capacity() << " ";
		first.push_back(i * 6);
	}
	std::cout << "}" << std::endl;
	std::cout << std::endl;

	std::cout << "test print :" << std::endl;
	printVec(first);
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	empty( void )
{
	std::cout << "test empty :" << std::endl;
	std::cout << std::endl;

	pl::vector<int> first;

	std::cout << "1st check :" << std::endl;
	std::cout << "empty : " << (first.empty() ? "true" : "false") << std::endl;
	std::cout << std::endl;

	for (int i = 0 ; i <= 10 ; i++)
		first.push_back(i);
	std::cout << "2nd check :" << std::endl;
	std::cout << "empty : " << (first.empty() ? "true" : "false") << std::endl;
	std::cout << std::endl;

	first.reserve(0);
	std::cout << "3rd check :" << std::endl;
	std::cout << "empty : " << (first.empty() ? "true" : "false") << std::endl;
	std::cout << std::endl;

	first.clear();
	std::cout << "4th check :" << std::endl;
	std::cout << "empty : " << (first.empty() ? "true" : "false") << std::endl;
	std::cout << std::endl;


	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	reserve( void )
{
	std::cout << "test reserve :" << std::endl;
	std::cout << std::endl;

	pl::vector<int>	first;

	std::cout << "1st check :" << std::endl;
	printVec(first);
	std::cout << std::endl;

	std::cout << "2nd check :" << std::endl;
	first.reserve(10);
	printVec(first);
	std::cout << std::endl;

	std::cout << "3rd check :" << std::endl;
	first.reserve(5);
	printVec(first);
	std::cout << std::endl;

	std::cout << "4th check :" << std::endl;
	first.reserve(100);
	printVec(first);
	std::cout << std::endl;

	std::cout << "5th check :" << std::endl;
	first.resize(120, 42);
	printVec(first);
	std::cout << std::endl;

	std::cout << "6th check :" << std::endl;
	first.reserve(242);
	printVec(first);
	std::cout << std::endl;

	std::cout << "7th check :" << std::endl;
	first.reserve(10);
	printVec(first);
	std::cout << std::endl;

	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}
int main ()
{
	size();
	max_size();
	resize();
	capacity();
	empty();
	reserve();

	return 0;
}

