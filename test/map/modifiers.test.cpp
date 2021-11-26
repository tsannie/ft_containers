/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:21:49 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/26 12:11:07 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.test.hpp"

void	insert( void )
{
	std::cout << "test insert :" << std::endl;
	std::cout << std::endl;
	pl::map<int, char>								first;
	pl::pair< pl::map<int, char>::iterator, bool>	ret;

	ret = first.insert( pl::pair<int, char>(1 , 'a') );
	checkRet(ret);

	ret = first.insert( pl::pair<int, char>(42, 'b') );
	checkRet(ret);

	ret = first.insert( pl::pair<int, char>(21 , 'c') );
	checkRet(ret);

	ret = first.insert( pl::pair<int, char>(42 , 'z') );
	checkRet(ret);

	first.insert(first.begin(), pl::pair<int, char>(84, 'c'));
	first.insert(first.end() , pl::pair<int, char>(168, 'd'));

	first.insert ( pl::pair<int, char>(336 , 'e') );
	first.insert ( pl::pair<int, char>(672 , 'f') );
	first.insert ( pl::pair<int, char>(1344 , 'g') );

	pl::map<int, char>	cpy;
	cpy.insert(first.find(21), first.find(672));

	printMap(first, "first");
	printMap(cpy, "cpy");
	std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}

void	erase( void )
{
	std::cout << "test erase :" << std::endl;
	std::cout << std::endl;
	ft::map<char,int>			mymap;
	ft::map<char,int>::iterator	it;

	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;
	mymap['d'] = 40;
	mymap['e'] = 50;
	mymap['f'] = 60;

	mymap.erase(mymap.find('b'));
	printMap(mymap, "mymap");

	mymap.erase('c');
	printMap(mymap, "mymap");

	it = mymap.find('e');
	mymap.erase ( it, mymap.end() );

	printMap(mymap, "mymap");
	std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}

void	swap( void )
{
	std::cout << "test swap :" << std::endl;
	pl::map<char, char>	foo, bar;
	pl::map<char, char>::const_iterator	it_foo, it_bar;
	int	i;

	for (i = 65 ; i <= 90 ; ++i)
		foo.insert( pl::pair<char, char>(i , 'A') );
	for (i = 97 ; i <= 122 ; ++i)
		bar.insert( pl::pair<char, char>(i , 'a') );

	it_foo = foo.begin();
	it_bar = bar.begin();
	printMap(foo, "foo");
	printMap(bar, "bar");

	std::cout << "it_foo == bar.begin() = " << (it_foo == bar.begin()
										? "true" : "false") << std::endl;
	std::cout << std::endl;

	foo.swap(bar);
	std::cout << "foo and bar swap" << std::endl;
	std::cout << std::endl;

	printMap(foo, "foo");
	printMap(bar, "bar");
	std::cout << "it_foo == bar.begin() = " << (it_foo == bar.begin()
									? "true" : "false") << std::endl;

	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	clear( void )
{
	std::cout << "test clear :" << std::endl;
	std::map<char,int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	printMap(mymap, "mymap");

	mymap.clear();
	printMap(mymap, "mymap");

	mymap['a']=1101;
	mymap['b']=2202;
	printMap(mymap, "mymap");
	std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}



void	modifiers( void )
{
	insert();
	erase();
	swap();
	clear();
}
