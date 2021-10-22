/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:00:14 by tsannie           #+#    #+#             */
/*   Updated: 2021/10/22 15:58:23 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <vector>
#include "../../srcs/vector.hpp"

/* TEST CONST */
	//ft::vector<int>::const_iterator end = cont.end();
	//ft::vector<int>::const_iterator it = cont.begin();

int main ()
{
	std::vector<int>				cont;

 	cont.push_back(42);

	cont.push_back(96);
	cont.push_back(96);
	cont.push_back(96);
	cont.push_back(96);
	cont.push_back(96);
	cont.push_back(96);
	cont.push_back(96);
	cont.push_back(96);
	//cont.reserve(6);

	//std::cout << ((it == end) ? "equal" : "not equal") << std::endl;

	//std::cout << ((it == end) ? "equal" : "not equal") << std::endl;

	//std::cout << ((it < end) ? "true" : "false") << std::endl;
	//std::cout << ((it > end) ? "true" : "false") << std::endl;

	std::vector<int>::iterator end = cont.end();
	std::vector<int>::iterator it = cont.begin();

	end = cont.end();
	for (it = cont.begin() ; it != end ; it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "capacity = " << cont.capacity() << std::endl;
	std::cout << "size = " << cont.size() << std::endl;
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
