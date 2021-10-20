/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:00:14 by tsannie           #+#    #+#             */
/*   Updated: 2021/10/20 18:59:55 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <vector>
#include "../../srcs/vector.hpp"

int main ()
{
	ft::vector<int>				cont;
	ft::vector<int>::iterator	it;
	ft::vector<int>::iterator	end;

	cont.push_back(42);
	cont.push_back(96);
	cont.push_back(51);
	cont.push_back(12);
	cont.push_back(21);

	std::cout << ((it == end) ? "equal" : "not equal") << std::endl;

	it = cont.begin();
	it++;
	std::cout << *it << std::endl;

	end = cont.end();
	for (it = cont.begin() ; it != end ; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
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
