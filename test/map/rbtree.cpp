/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:14:37 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/17 21:04:01 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/RBTree.hpp"
#include "../../includes/utility.hpp"
#include "../../map.hpp"
#include <map>

#define	pl	std

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
	pl::map<char,std::string> mymap;

	mymap['a'] = "an element";
	mymap['b'] = "another element";
	mymap['c'] = mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << '\n';
	std::cout << "mymap['b'] is " << mymap['b'] << '\n';
	std::cout << "mymap['c'] is " << mymap['c'] << '\n';
	std::cout << "mymap['d'] is " << mymap['d'] << '\n' << std::endl;

	printVec(mymap, "mymap");

	return 0;

	pl::map<char,int> foo, bar;

	foo.insert( pl::pair<char, int>('a', 100) );
	foo.insert( pl::pair<char, int>('b', 200) );
	foo.insert( pl::pair<char, int>('c', 300) );

	/*foo.insert( pl::pair<char, int>('b', 200) );
	foo.insert( pl::pair<char, int>('c', 200) );
	foo.insert( pl::pair<char, int>('x', 100) );
	foo.insert( pl::pair<char, int>('y', 200) );
	foo.insert( pl::pair<char, int>('z', 200) );*/

	bar = foo;


	//bar.insert( pl::pair<char, int>('a', 11) );
	//bar.insert( pl::pair<char, int>('b', 22) );
	//bar.insert( pl::pair<char, int>('c', 33) );

	//foo.swap(bar);

	std::cout << "foo contains:\n";
	for (pl::map<char,int>::iterator it = foo.begin() ; it != foo.end() ; ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << std::endl;

	std::cout << "bar contains:\n";
	for (pl::map<char,int>::iterator it = bar.begin() ; it != bar.end() ; ++it)
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
