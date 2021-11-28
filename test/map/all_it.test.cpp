/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_it.test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:40:10 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/28 18:17:09 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.test.hpp"

void	iterator_is_const( void )
{
	std::cout << "test is_const :" << std::endl;
	std::cout << std::endl;
	pl::map<int, char>	first;

	for (int i = 0 ; i <= 42 ; ++i)
		first.insert( pl::pair<int, char>(i, 'z') );

	pl::map<int, char>::iterator				it   = first.begin();
	pl::map<int, char>::const_iterator			cit  = first.begin();
	pl::map<int, char>::reverse_iterator		rit  = first.rbegin();
	pl::map<int, char>::const_reverse_iterator	crit = first.rbegin();

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

	std::cout << "test on it->first : " << std::endl;
	std::cout << "it   = ";
	std::cout << (isConst(it->first) ? "const" : "not const") << std::endl;
	std::cout << "cit  = ";
	std::cout << (isConst(cit->first) ? "const" : "not const") << std::endl;
	std::cout << "rit  = ";
	std::cout << (isConst(rit->first) ? "const" : "not const") << std::endl;
	std::cout << "crit = ";
	std::cout << (isConst(crit->first) ? "const" : "not const") << std::endl;
	std::cout << std::endl;

	std::cout << "test on it->second : " << std::endl;
	std::cout << "it   = ";
	std::cout << (isConst(it->second) ? "const" : "not const") << std::endl;
	std::cout << "cit  = ";
	std::cout << (isConst(cit->second) ? "const" : "not const") << std::endl;
	std::cout << "rit  = ";
	std::cout << (isConst(rit->second) ? "const" : "not const") << std::endl;
	std::cout << "crit = ";
	std::cout << (isConst(crit->second) ? "const" : "not const") << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}

void	print_content( void )
{
	std::cout << "test print content :" << std::endl;
	std::cout << std::endl;

	pl::map<int, char>	first;
	pl::map<int, char>::iterator				it, end;
	pl::map<int, char>::const_iterator			cit, cend;
	pl::map<int, char>::reverse_iterator		rit, rend;
	pl::map<int, char>::const_reverse_iterator	crit, crend;

	for (int i = 0, e = 65 ; i <= 42 ; ++i, ++e)
	{
		e = (e > 90 ? 65 : e);
		first.insert( pl::pair<int, char>(i, e) );
	}

	std::cout << "---------------------\niterator:" << std::endl;
	end = first.end();
	for (it = first.begin() ; it != end ; ++it)
		std::cout << it->first << " => " << it->second << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "---------------------\nconst iterator:" << std::endl;
	cend = first.end();
	for (cit = first.begin() ; cit != cend ; ++cit)
		std::cout << cit->first << " => " << cit->second << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "---------------------\nrevserse iterator:" << std::endl;
	rend = first.rend();
	for (rit = first.rbegin() ; rit != rend ; ++rit)
		std::cout << rit->first << " => " << rit->second << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "---------------------\nconst revserse iterator:" << std::endl;
	crend = first.rend();
	for (crit = first.rbegin() ; crit != crend ; ++crit)
		std::cout << crit->first << " => " << crit->second << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	bidirectional_access_op( void )
{
	std::cout << "test bidirectional_access_op :" << std::endl;
	int								e = 0;
	pl::map<int, char>				first;
	pl::map<int, char>::iterator	it;

	for (int i = 0, e = 65 ; i <= 42 ; ++i, ++e)
	{
		e = (e > 90 ? 65 : e);
		first.insert( pl::pair<int, char>(i, e) );
	}

	it = first.begin();
	pl::map<int, char>::iterator	cpy(it);
	equals(it, cpy, e);

	std::cout << cpy->first << " == " << it->first << std::endl;
	++it;
	std::cout << it->first << std::endl;
	it++;
	std::cout << it->first << std::endl;
	it++;

	std::cout << it->second << std::endl;
	it->second = 42;
	std::cout << it->second << std::endl;

	std::cout << it->first << std::endl;
	--it;
	std::cout << it->first << std::endl;
	it--;
	std::cout << it->first << std::endl;
	std::cout << it->first << std::endl;

	equals(it, cpy, e);
}

void	all_it( void )
{
	iterator_is_const();
	print_content();
	bidirectional_access_op();
}
