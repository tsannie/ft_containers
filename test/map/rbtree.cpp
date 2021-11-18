/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:14:37 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/18 14:49:40 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/RBTree.hpp"
#include "../../includes/utility.hpp"
#include "../../map.hpp"
#include <map>

#define	pl	ft

template <typename T>
void printVec(T &vec, std::string const & name)
{
	typename	T::iterator	it;
	typename	T::iterator	end;

	std::cout << name << " contains:" << std::endl;

	end = vec.end();
	for (it = vec.begin() ; it != end ; it++)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "size = " << vec.size() << std::endl;
	std::cout << "------------------------\n" << std::endl;
}


int main ()
{
	pl::map<char,int> mymap;

	pl::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	/*pl::map<char,int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mycomp((*it++).first, highest) );

	std::cout << '\n';

	return 0;*/
}
