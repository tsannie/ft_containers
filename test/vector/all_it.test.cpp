/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_it.test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:40:10 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/25 13:32:43 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.test.hpp"

void	iterator_is_const( void )
{
	std::cout << "test is const :" << std::endl;
	pl::vector<int>	first(1, 42);
	pl::vector<int>::iterator				it   = first.begin();
	pl::vector<int>::const_iterator			cit  = first.begin();
	pl::vector<int>::reverse_iterator		rit  = first.rbegin();
	pl::vector<int>::const_reverse_iterator	crit = first.rbegin();

	std::cout << "it  = ";
	std::cout << (isConst(*it) ? "const" : "not const") << std::endl;
	std::cout << "cit = ";
	std::cout << (isConst(*cit) ? "const" : "not const") << std::endl;
	std::cout << "rit = ";
	std::cout << (isConst(*rit) ? "const" : "not const") << std::endl;
	std::cout << "crit = ";
	std::cout << (isConst(*crit) ? "const" : "not const") << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	print_content( void )
{
	std::cout << "test print content :" << std::endl;
	pl::vector<char>	first;
	pl::vector<char>::iterator				it, end;
	pl::vector<char>::const_iterator			cit, cend;
	pl::vector<char>::reverse_iterator		rit, rend;
	pl::vector<char>::const_reverse_iterator	crit, crend;

	for (int i = 97 ; i <= 122 ; ++i)
		first.push_back(i);

	std::cout << "iterator = [ ";
	end = first.end();
	for (it = first.begin() ; it != end ; ++it)
		std::cout << *it << " ";
	std::cout << "]" << std::endl;
	std::cout << std::endl;

	std::cout << "const iterator = [ ";
	cend = first.end();
	for (cit = first.begin() ; cit != cend ; ++cit)
		std::cout << *cit << " ";
	std::cout << "]" << std::endl;
	std::cout << std::endl;

	std::cout << "revserse iterator = [ ";
	rend = first.rend();
	for (rit = first.rbegin() ; rit != rend ; ++rit)
		std::cout << *rit << " ";
	std::cout << "]" << std::endl;
	std::cout << std::endl;

	std::cout << " const revserse iterator = [ ";
	crend = first.rend();
	for (crit = first.rbegin() ; crit != crend ; ++crit)
		std::cout << *crit << " ";
	std::cout << "]" << std::endl;
	std::cout << std::endl;

	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}

void	random_access_op( void )
{
	std::cout << "test random_access_op :" << std::endl;
	int							e = 0;
	pl::vector<int>				first;
	pl::vector<int>::iterator	it;

	for (int i = 1 ; i < 100 ; ++i)
		first.push_back(i);
	it = first.begin();
	pl::vector<int>::iterator	cpy(it);
	relation(it, cpy, e);

	std::cout << *cpy << " == " << *it << std::endl;
	++it;
	std::cout << *it << std::endl;
	it++;
	std::cout << *it << std::endl;
	it++;

	std::cout << *it << std::endl;
	*it = 42;
	std::cout << *it << std::endl;

	std::cout << *it << std::endl;
	--it;
	std::cout << *it << std::endl;
	it--;
	std::cout << *it-- << std::endl;
	std::cout << *it << std::endl;

	std::cout << *(it + 5) << std::endl;
	std::cout << *(10 + it) << std::endl;
	it = it + 20;

	std::cout << *(it - 5) << std::endl;

	std::cout << it - cpy << std::endl;
	relation(it, cpy, e);

	it += 5;
	std::cout << *it << std::endl;
	it -= 15;
	std::cout << *it << std::endl;

	std::cout << it[50] << std::endl;
	std::cout << it[10] << std::endl;
	std::cout << it[42] << std::endl;

}

void	all_it( void )
{
	iterator_is_const();
	print_content();
	random_access_op();
}
