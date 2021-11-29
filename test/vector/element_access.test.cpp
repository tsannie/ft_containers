/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_access.test.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 07:09:14 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/29 08:01:39 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.test.hpp"

void	at( void )
{
	std::cout << "test at :" << std::endl;
	std::cout << std::endl;
	pl::vector<int>	myvector(10, 42);

	for (size_t i = 0; i < myvector.size(); ++i)
		myvector.at(i) = i * 6;
	printVec(myvector);

	try
	{
		myvector.at(15);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	op_access( void )
{
	std::cout << "test op_access :" << std::endl;
	std::cout << std::endl;
	pl::vector<int>	myvector(10, 42);

	printVec(myvector);
	for (size_t i = 0 ; i < myvector.capacity() ; i++)
		myvector[i] = i * 6;

	printVec(myvector);

	for (size_t i = 0 ; i < myvector.capacity() ; i++)
		std::cout << myvector[i] << " | ";
	std::cout << std::endl;


	printVec(myvector);
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	front( void )
{
	std::cout << "test front :" << std::endl;
	pl::vector<int> myvector;

	for (int i = 1 ; i < 20 ; i++)
		myvector.push_back(i * 42);

	printVec(myvector);
	std::cout << "myvector.front() = " << myvector.front() << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	back( void )
{
	std::cout << "test back :" << std::endl;
	pl::vector<int> myvector;

	for (int i = 1 ; i < 20 ; i++)
		myvector.push_back(i * 42);

	printVec(myvector);
	std::cout << "myvector.back() = " << myvector.back() << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	element_access( void )
{
	op_access();
	at();
	front();
	back();
}
