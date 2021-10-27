/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:00:14 by tsannie           #+#    #+#             */
/*   Updated: 2021/10/27 15:57:11 by tsannie          ###   ########.fr       */
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
	ft::vector<int> vct(6, 21);
	ft::vector<int> vct2(7, 5);

	for (size_t i = 0 ; i < 16 ; i++)
		vct.push_back(i * 36);

	//vct2.reserve(500);
	//printVec(vct);
	printVec(vct2);
	vct2.assign(vct.begin(), vct.end());
	//vct2.insert(vct2.begin() + 5 ,vct.begin(), vct.end());
	printVec(vct2);
	//printVec(vct);


	return (0);
}
