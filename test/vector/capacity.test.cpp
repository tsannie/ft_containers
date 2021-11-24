/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.test.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:52:33 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/24 16:13:59 by tsannie          ###   ########.fr       */
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

	pl::vector<int> myvector;

	std::cout << "max_size :" << myvector.max_size() << std::endl;


	for (int i = 0; i < 500; i++)
		myvector.push_back(i * 6);

	std::cout << "max_size: " << myvector.max_size() << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void resize( void )
{
	std::cout << "test resize :" << std::endl;
	std::cout << std::endl;

	pl::vector<int> myvector;

	// set some initial content:
	for (int i = 0; i < 50 ; i++)
		myvector.push_back(i);

	std::cout << "1st check :" << std::endl;
	printVec(myvector);

	std::cout << "2nd check :" << std::endl;
	myvector.resize(5);
	printVec(myvector);

	std::cout << "3rd check :" << std::endl;
	myvector.resize(8, 100);
	printVec(myvector);

	std::cout << "4th check :" << std::endl;
	myvector.resize(70);
	printVec(myvector);

	myvector.resize(0, 0);
	std::cout << "5th check :" << std::endl;
	printVec(myvector);

	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	capacity( void )
{
	std::cout << "test capacity :" << std::endl;
	std::cout << std::endl;

	pl::vector<int> myvector;

	std::cout << "{ ";
	for (int i = 0; i < 550; i++)
	{
		if (!(i % 10))
			std::cout << myvector.capacity() << " ";
		myvector.push_back(i * 6);
	}
	std::cout << "}" << std::endl;
	std::cout << std::endl;

	std::cout << "test print :" << std::endl;
	printVec(myvector);
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	empty( void )
{
	std::cout << "test empty :" << std::endl;
	std::cout << std::endl;

	pl::vector<int> myvector;

	std::cout << "1st check :" << std::endl;
	std::cout << "empty : " << (myvector.empty() ? "true" : "false") << std::endl;
	std::cout << std::endl;

	for (int i = 0 ; i <= 10 ; i++)
		myvector.push_back(i);
	std::cout << "2nd check :" << std::endl;
	std::cout << "empty : " << (myvector.empty() ? "true" : "false") << std::endl;
	std::cout << std::endl;

	myvector.reserve(0);
	std::cout << "3rd check :" << std::endl;
	std::cout << "empty : " << (myvector.empty() ? "true" : "false") << std::endl;
	std::cout << std::endl;

	myvector.clear();
	std::cout << "4th check :" << std::endl;
	std::cout << "empty : " << (myvector.empty() ? "true" : "false") << std::endl;
	std::cout << std::endl;


	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	reserve( void )
{
	std::cout << "test reserve :" << std::endl;
	std::cout << std::endl;

	pl::vector<int>	myvector;

	std::cout << "1st check :" << std::endl;
	printVec(myvector);
	std::cout << std::endl;

	std::cout << "2nd check :" << std::endl;
	myvector.reserve(10);
	printVec(myvector);
	std::cout << std::endl;

	std::cout << "3rd check :" << std::endl;
	myvector.reserve(5);
	printVec(myvector);
	std::cout << std::endl;

	std::cout << "4th check :" << std::endl;
	myvector.reserve(100);
	printVec(myvector);
	std::cout << std::endl;

	std::cout << "5th check :" << std::endl;
	myvector.resize(120, 42);
	printVec(myvector);
	std::cout << std::endl;

	std::cout << "6th check :" << std::endl;
	myvector.reserve(242);
	printVec(myvector);
	std::cout << std::endl;

	std::cout << "7th check :" << std::endl;
	myvector.reserve(10);
	printVec(myvector);
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

