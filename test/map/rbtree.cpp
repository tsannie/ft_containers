/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:14:37 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/16 22:32:01 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/RBTree.hpp"
#include "../../includes/utility.hpp"
#include "../../map.hpp"
#include <map>

#define	pl	std

int	main(void)
{
	pl::map<char,int> mymap;

	// first insert function version (single parameter):
	mymap.insert ( pl::pair<char,int>('a',100) );
	mymap.insert ( pl::pair<char,int>('z',200) );

	pl::pair< pl::map<char, int>::iterator, bool> ret;

	std::cout << std::endl;
	std::cout << "insert fraude" << std::endl;
	ret = mymap.insert( pl::pair<char, int >('z',500) );

	if (ret.second == false)
	{
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	pl::map<char,int>::iterator it = mymap.begin();
	/*mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

	// third insert function version (range insertion):
	std::map<char,int> anothermap;
	anothermap.insert(mymap.begin(),mymap.find('c'));*/

	// showing contents:
	std::cout << "mymap contains:\n";
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	/*std::cout << "anothermap contains:\n";
	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';*/

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
