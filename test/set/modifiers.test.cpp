/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.test.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 09:21:49 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/26 12:18:15 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.test.hpp"

void	insert( void )
{
	std::cout << "test insert :" << std::endl;
	std::cout << std::endl;
	pl::set<int>								first;
	pl::pair< pl::set<int>::iterator, bool>	ret;

	ret = first.insert(1);
	checkRet(ret);

	ret = first.insert(42);
	checkRet(ret);

	ret = first.insert(21);
	checkRet(ret);

	ret = first.insert(42);
	checkRet(ret);

	first.insert(first.begin(), 84);
	first.insert(first.end(), 168);

	first.insert(336);
	first.insert(672);
	first.insert(1344);

	pl::set<int>	cpy;
	cpy.insert(first.find(21), first.find(672));

	printSet(first, "first");
	printSet(cpy, "cpy");
	std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}

void	erase( void )
{
	std::cout << "test erase :" << std::endl;
	std::cout << std::endl;
	ft::set<char>			myset;
	ft::set<char>::iterator	it;

	myset.insert('a');
	myset.insert('b');
	myset.insert('c');
	myset.insert('d');
	myset.insert('e');
	myset.insert('f');

	myset.erase(myset.find('b'));
	printSet(myset, "myset");

	myset.erase('c');
	printSet(myset, "myset");

	it = myset.find('e');
	myset.erase ( it, myset.end() );

	printSet(myset, "myset");
	std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}

void	swap( void )
{
	std::cout << "test swap :" << std::endl;
	pl::set<char>					foo, bar;
	pl::set<char>::const_iterator	it_foo, it_bar;
	int	i;

	for (i = 65 ; i <= 90 ; ++i)
		foo.insert(i);
	for (i = 97 ; i <= 122 ; ++i)
		bar.insert(i);

	it_foo = foo.begin();
	it_bar = bar.begin();
	printSet(foo, "foo");
	printSet(bar, "bar");

	std::cout << "it_foo == bar.begin() = " << (it_foo == bar.begin()
										? "true" : "false") << std::endl;
	std::cout << std::endl;

	foo.swap(bar);
	std::cout << "foo and bar swap" << std::endl;
	std::cout << std::endl;

	printSet(foo, "foo");
	printSet(bar, "bar");
	std::cout << "it_foo == bar.begin() = " << (it_foo == bar.begin()
									? "true" : "false") << std::endl;

	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	clear( void )
{
	std::cout << "test clear :" << std::endl;
	std::set<char> myset;

	myset.insert('x');
	myset.insert('y');
	myset.insert('z');

	printSet(myset, "myset");

	myset.clear();
	printSet(myset, "myset");

	myset.insert('a');
	myset.insert('b');
	printSet(myset, "myset");
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
