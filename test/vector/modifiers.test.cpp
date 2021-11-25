/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:21:49 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/25 11:36:09 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.test.hpp"

void	assign( void )
{
	std::cout << "test assign :" << std::endl;
	pl::vector<int>	first;
	pl::vector<int>	second;

	first.assign(7,100);
	second.assign(first.begin(), first.end());

	printVec(first);
	printVec(second);
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	push_back( void )
{
	std::cout << "test push_back :" << std::endl;
	pl::vector<int>	first;

	for (int i = 0 ; i < 33 ; ++i)
	{
		first.push_back(i * 42);
		printVec(first);
	}
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	pop_back( void )
{
	std::cout << "test push_back :" << std::endl;
	pl::vector<int>	first;

	for (int i = 0 ; i < 33 ; ++i)
		first.push_back(i * 42);

	printVec(first);
	for (int i = 0 ; first.size() != 0 ; ++i)
		first.pop_back();

	printVec(first);
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	insert( void )
{
	std::cout << "test insert :" << std::endl;
	pl::vector<int>				first(3, 42);
	pl::vector<int>::iterator	it;
	printVec(first);

	it = first.insert(first.begin() + 1 , 21);
	printVec(first);
	std::cout << "it point on : " << *it << std::endl;

	first.insert(it, 8, 84);
	printVec(first);

	pl::vector<int>	second(5, 51);
	printVec(second);
	first.insert(first.begin() + 2, second.begin(), second.end());
	printVec(first);

	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	erase( void )
{
	std::cout << "test erase :" << std::endl;
	pl::vector<int>	first;

	for (int i = 0 ; i < 42 ; ++i)
		first.push_back(i * 6);

	printVec(first);
	first.erase(first.begin() + 35);

	printVec(first);
	first.erase(first.begin() + 5, first.end() - 5);

	printVec(first);

	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	swap( void )
{
	std::cout << "test swap :" << std::endl;
	pl::vector<char>	foo, bar;
	pl::vector<char>::const_iterator	it_foo, it_bar;
	int	i;

	for (i = 65 ; i <= 90 ; ++i)
		foo.push_back(i);
	for (i = 97 ; i <= 122 ; ++i)
		bar.push_back(i);

	it_foo = foo.begin();
	it_bar = bar.begin();
	std::cout << "foo contains :" << std::endl;
	printVec(foo);
	std::cout << "bar contains :" << std::endl;
	printVec(bar);

	std::cout << "it_foo == bar.begin() = " << (it_foo == bar.begin()
										? "true" : "false") << std::endl;
	std::cout << std::endl;

	foo.swap(bar);
	std::cout << "foo and bar swap" << std::endl;
	std::cout << std::endl;

	std::cout << "foo contains :" << std::endl;
	printVec(foo);
	std::cout << "bar contains :" << std::endl;
	printVec(bar);
	std::cout << "it_foo == bar.begin() = " << (it_foo == bar.begin()
									? "true" : "false") << std::endl;

	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	clear( void )
{
	std::cout << "test clear :" << std::endl;
	pl::vector<int>	first;

	for (int i = 0 ; i < 50 ; ++i)
		first.push_back(i * 42);
	printVec(first);

	first.clear();
	printVec(first);
}

void	modifiers( void )
{
	assign();
	push_back();
	pop_back();
	insert();
	erase();
	swap();
	clear();
}
