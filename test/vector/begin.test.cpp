/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:00:14 by tsannie           #+#    #+#             */
/*   Updated: 2021/10/27 20:26:54 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <vector>
#include "../../vector.hpp"

/* TEST CONST */

template <typename T>
void printVec(T &vec)
{
	typename T::iterator it;
	typename T::iterator end;

	std::cout << "[ ";
	end = vec.end();
	for (it = vec.begin() ; it != end ; it++)
		std::cout << *it << " ";
	std::cout << "]" << std::endl;
	std::cout << "capacity = " << vec.capacity() << std::endl;
	std::cout << "size = " << vec.size() << std::endl << std::endl;
}

int		main(void)
{
	const int size = 5;
	std::vector<int> vct(size);
	std::vector<int>::reverse_iterator it = vct.rbegin();
	std::vector<int>::const_reverse_iterator ite = vct.rbegin();

	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;

	it = it + 5;
	it = 1 + it;
	it = it - 4;
	std::cout << *(it += 2) << std::endl;
	std::cout << *(it -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

	std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	std::cout << "(it == const_it): " << (ite == it) << std::endl;
	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	printVec(vct);
	return (0);
}
