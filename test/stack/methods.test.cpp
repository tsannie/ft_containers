/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.test.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:37:43 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/25 18:05:37 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.test.hpp"


void	empty( void )
{
	std::cout << "test empty :" << std::endl;
	std::cout << std::endl;
	pl::stack<int>	stack;

	for (int i = 0 ; i < 50 ; i++)
		stack.push(i * 6);

	int e = 0;
	while (!stack.empty())
	{
		stack.pop();
		e++;
	}
	std::cout << "e = " << e << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	size( void )
{
	std::cout << "test size :" << std::endl;
	std::cout << std::endl;
	pl::stack<int>	myints;

	std::cout << "size = " << myints.size() << std::endl;
	for (int i = 0 ; i < 50 ; i++)
		myints.push(i);

	std::cout << "size = " << myints.size() << std::endl;

	myints.pop();
	std::cout << "size = " << myints.size() << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}

void	top( void )
{
	std::cout << "test top :" << std::endl;
	std::cout << std::endl;
	pl::stack<int>	stack;

	for (int i = 0 ; i <= 42 ; i++)
		stack.push(i);

	std::cout << "[ ";
	for (int i = 0 ; i <= 42 ; i++)
	{
		std::cout << stack.top() << " ";
		stack.pop();
	}
	std::cout << "]" << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}

void	push( void )
{
	std::cout << "test push :" << std::endl;
	pl::stack<int>	first;

	for (int i = 0; i <= 42; ++i)
		first.push(i);
	std::cout << "size = " << first.size() << std::endl;
	std::cout << first.top() << " " << std::endl;
	first.pop();
	std::cout << first.top() << " " << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}

void	pop( void )
{
	pl::stack<int> first;

	for (int i = 0; i <= 42; ++i)
		first.push(i);

	while (!first.empty())
	{
		std::cout << "size = " << first.size() << std::endl;
		first.pop();
	}
	std::cout << std::endl;
}
void	methods( void )
{
	empty();
	size();
	top();
	push();
	pop();
}
