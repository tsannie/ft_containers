/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:14:37 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/19 04:02:54 by tsannie          ###   ########.fr       */
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
	pl::map<char,int>::iterator it, end;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=50;
	mymap['d']=60;
	mymap['e']=70;
	mymap['f']=80;
	mymap['g']=100;

	//itlow = mymap.lower_bound('b');  // itlow points to b
	//std::cout << itlow->first << " => " << itlow->second << '\n';

	//itup = mymap.upper_bound('d');   // itup points to e (not d!)
	//std::cout << itup->first << " => " << itup->second << '\n';

	end = mymap.find('f');
	for (it = mymap.find('b') ; it != end ; it++)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "size = " << mymap.size() << std::endl;

	mymap.erase(mymap.find('b'), mymap.find('f'));        // erases [itlow,itup)


	// print content:
	//printVec(mymap, "mymap");

	return 0;
}
