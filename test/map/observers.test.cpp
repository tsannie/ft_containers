/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observers.test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:35:59 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/26 11:04:14 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.test.hpp"

void	key_comp( void )
{
	std::cout << "test key_comp :" << std::endl;
	std::cout << std::endl;
	pl::map<char, int, comp> mymap;

	pl::map<char, int, comp>::key_compare mycomp = mymap.key_comp();

	mymap['a'] = 100;
	mymap['b'] = 200;
	mymap['c'] = 300;
	mymap['d'] = 300;
	mymap['e'] = 300;

	std::cout << "mymap contains:\n";

	char highest = mymap.rbegin()->first;     // key value of last element

	pl::map<char, int, comp>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << std::endl;
	} while ( mycomp((*it++).first, highest) );

	pl::map<char, int> mymap2;
	pl::map<char, int>::key_compare mycomp2 = mymap2.key_comp();

	mymap2['a'] = 100;
	mymap2['b'] = 200;
	mymap2['c'] = 300;
	mymap2['d'] = 300;
	mymap2['e'] = 300;

	std::cout << "mymap contains:\n";

	char highest2 = mymap2.rbegin()->first;     // key value of last element

	pl::map<char, int>::iterator it2 = mymap2.begin();
	do {
		std::cout << it2->first << " => " << it2->second << std::endl;
	} while ( mycomp2((*it2++).first, highest2) );

	std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}

void	value_comp( void )
{
	std::cout << "test value_comp :" << std::endl;
	pl::map<char, int> mymap;

	mymap['x'] = 1001;
	mymap['y'] = 2002;
	mymap['z'] = 3003;

	std::cout << "mymap contains:\n";

	pl::pair<char, int> highest = *mymap.rbegin();

	pl::map<char, int>::iterator it = mymap.begin();
	do {
		std::cout << it->first << " => " << it->second << '\n';
	} while ( mymap.value_comp()(*it++, highest) );
	std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}

void	observers( void )
{
	key_comp();
	value_comp();
}
