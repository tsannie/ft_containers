/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:00:14 by tsannie           #+#    #+#             */
/*   Updated: 2021/10/27 18:02:53 by tsannie          ###   ########.fr       */
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
	ft::vector<int> vct(size);
	ft::vector<int>::iterator it_ = vct.begin();
	ft::vector<int>::reverse_iterator it(it_);

	for (int i = 0; i < size; ++i)
		vct[i] = (i + 1) * 5;
	printVec(vct);

	std::cout << (it_ == it.base()) << std::endl;
	std::cout << (it_ == (it + 3).base()) << std::endl;

	std::cout << *(it.base() + 1) << std::endl;
	std::cout << *(it - 3) << std::endl;
	std::cout << *(it - 3).base() << std::endl;
	it -= 3;
	std::cout << *it.base() << std::endl;

	std::cout << "TEST OFFSET" << std::endl;
	std::cout << *(it) << std::endl;
	std::cout << *(it).base() << std::endl;
	std::cout << *(it - 0) << std::endl;
	std::cout << *(it - 0).base() << std::endl;
	std::cout << *(it - 1).base() << std::endl;

	return (0);
}
