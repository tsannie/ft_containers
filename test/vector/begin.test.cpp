/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:00:14 by tsannie           #+#    #+#             */
/*   Updated: 2021/10/22 23:57:02 by tsannie          ###   ########.fr       */
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
	ft::vector<int>	cont(100, 42);

	//for (int i = 0 ; i < 16 ; i++)
	//	cont.push_back(i);
	printVec(cont);

	//cont.push_back(6);
	//std::cout << ((it == end) ? "equal" : "not equal") << std::endl;

	//std::cout << ((it == end) ? "equal" : "not equal") << std::endl;

	//std::cout << ((it < end) ? "true" : "false") << std::endl;
	//std::cout << ((it > end) ? "true" : "false") << std::endl;

	/*ft::vector<int>::iterator end = cont.end();
	ft::vector<int>::iterator it = cont.begin();

	end = cont.end();
	for (it = cont.begin() ; it != end ; it++)
		std::cout << *it << " ";
	std::cout << std::endl;*/

	//std::cout << "max = " << cont.max_size() << std::endl;

	//std::vector<int>				cont;

	//cont.push_back(5);


	/*std::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';*/

	return 0;
}
