/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:14:37 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/17 13:03:24 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/RBTree.hpp"
#include "../../includes/utility.hpp"
#include "../../map.hpp"
#include <map>

#define	pl	ft

int	main(void)
{
	pl::map<char,int> mymap;
	pl::map<char,int>::iterator it;

	// insert some values:
	mymap.insert( pl::pair<char,int>('a',10) );
	mymap.insert( pl::pair<char,int>('b',20) );
	mymap.insert( pl::pair<char,int>('c',30) );
	mymap.insert( pl::pair<char,int>('d',40) );
	mymap.insert( pl::pair<char,int>('e',50) );
	mymap.insert( pl::pair<char,int>('f',60) );


	it = mymap.find('b');
	std::cout << "find it " << it->first << " => " << it->second << '\n';
	mymap.erase (it);                   // erasing by iterator

	//std::cout << mymap.erase ('a') << std::endl;

	//it = mymap.find ('e');
	//mymap.erase ( it, mymap.end() );    // erasing by range

	// show content:
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	return 0;
}


/*{
	pl::map<int, char>	test;

	std::cout << "test.size()\t=\t" << test.size() << std::endl;

	test.insert( pl::pair<int, char>(1, 'c') );

	std::cout << "test.size()\t=\t" << test.size() << std::endl;

	//test.erase(1, 'c');

	std::cout << "test.max_size()\t=\t" << test.max_size() << std::endl;

	std::cout << std::endl;
	//std::cout << it->first << " => " << it->second << '\n';
	//std::cout << it->first << " => " << it->second << '\n';


	//std::cout << it->first << " => " << it->second << '\n';

	pl::map<int, char>::iterator	ite = test.end();
	pl::map<int, char>::iterator	it = test.begin();

	std::cout << "ite(end)  : " << ite->first << " => " << ite->second << '\n';
	std::cout << "it(begin) : " << it->first << " => " << it->second << '\n';\
	for (; ite != it; --ite)
		std::cout << ite->first << " => " << ite->second << '\n';
	std::cout << ite->first << " => " << ite->second << '\n';

	//test.deleteNode(2);

	//test.printTree();
}*/
