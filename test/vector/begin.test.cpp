/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:00:14 by tsannie           #+#    #+#             */
/*   Updated: 2021/10/24 18:31:40 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <vector>
#include "../../srcs/vector.hpp"

/* TEST CONST */
	//ft::vector<int>::const_iterator end = cont.end();
	//ft::vector<int>::const_iterator it = cont.begin();


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

int main ()
{
	ft::vector<int>	cont;

	cont.reserve(50);
	for (int i = 0 ; i < 40 ; i++)
	cont.push_back(i);
	printVec(cont);

	ft::vector<int>::iterator	pos(cont.begin());
	cont.insert(pos + 10, 5, 99);

	printVec(cont);
	//printVec(vec);


	/*std::vector<int>::iterator	first = cont.begin() + 20;
	ft::vector<int>::iterator	last = cont.end();
	ft::vector<char>	vec(first, last);*/
	//std::cout << ((it < end) ? "true" : "false") << std::endl;

	return 0;
}
