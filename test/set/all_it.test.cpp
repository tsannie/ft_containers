/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_it.test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:40:10 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/26 12:03:19 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.test.hpp"

void	iterator_is_const( void )
{
	std::cout << "test is_const :" << std::endl;
	std::cout << std::endl;
	pl::set<int>	first;

	for (int i = 0 ; i <= 42 ; ++i)
		first.insert( i );

	pl::set<int>::iterator					it   = first.begin();
	pl::set<int>::const_iterator			cit  = first.begin();
	pl::set<int>::reverse_iterator			rit  = first.rbegin();
	pl::set<int>::const_reverse_iterator	crit = first.rbegin();

	std::cout << "test on *it : " << std::endl;
	std::cout << "it   = ";
	std::cout << (isConst(*it) ? "const" : "not const") << std::endl;
	std::cout << "cit  = ";
	std::cout << (isConst(*cit) ? "const" : "not const") << std::endl;
	std::cout << "rit  = ";
	std::cout << (isConst(*rit) ? "const" : "not const") << std::endl;
	std::cout << "crit = ";
	std::cout << (isConst(*crit) ? "const" : "not const") << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}

void	print_content( void )
{
	std::cout << "test print content :" << std::endl;
	std::cout << std::endl;

	pl::set<int>	first;
	pl::set<int>::iterator					it, end;
	pl::set<int>::const_iterator			cit, cend;
	pl::set<int>::reverse_iterator			rit, rend;
	pl::set<int>::const_reverse_iterator	crit, crend;

	for (int i = 0 ; i <= 42 ; ++i)
		first.insert(i);

	std::cout << "---------------------\niterator:" << std::endl;
	end = first.end();
	for (it = first.begin() ; it != end ; ++it)
		std::cout << *it << " => " << *it << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "---------------------\nconst iterator:" << std::endl;
	cend = first.end();
	for (cit = first.begin() ; cit != cend ; ++cit)
		std::cout << *cit << " => " << *cit << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "---------------------\nrevserse iterator:" << std::endl;
	rend = first.rend();
	for (rit = first.rbegin() ; rit != rend ; ++rit)
		std::cout << *rit << " => " << *rit << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "---------------------\nconst revserse iterator:" << std::endl;
	crend = first.rend();
	for (crit = first.rbegin() ; crit != crend ; ++crit)
		std::cout << *crit << " => " << *crit << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	bidirectional_access_op( void )
{
	std::cout << "test bidirectional_access_op :" << std::endl;
	int						e = 0;
	pl::set<int>			first;
	pl::set<int>::iterator	it;

	for (int i = 0 ; i <= 42 ; ++i)
		first.insert(i);

	it = first.begin();
	pl::set<int>::iterator	cpy(it);
	equals(it, cpy, e);

	std::cout << *cpy << " == " << *it << std::endl;
	++it;
	std::cout << *it << std::endl;
	it++;
	std::cout << *it << std::endl;
	it++;

	std::cout << *it << std::endl;
	--it;
	std::cout << *it << std::endl;
	it--;
	std::cout << *it << std::endl;
	std::cout << *it << std::endl;

	equals(it, cpy, e);
}

void	all_it( void )
{
	iterator_is_const();
	print_content();
	bidirectional_access_op();
}
