/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.test.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:53:36 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/29 08:12:04 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TEST_HPP
# define VECTOR_TEST_HPP

#include <iostream>
#include <ostream>
#include <vector>
#include <set>
#include "../../vector.hpp"

#ifndef pl
# define pl ft
#endif

# if pl == ft
	# define print_pl "ft"
# else
	# define print_pl "std"
# endif

template <typename T>
void printVec(T & vec)
{
	typename T::iterator it;
	typename T::iterator end;

	std::cout << "[ ";
	end = vec.end();
	for (it = vec.begin() ; it != end ; it++)
		std::cout << *it << " ";
	std::cout << "]" << std::endl;
	std::cout << "capacity = " << vec.capacity() << std::endl;
	std::cout << "size = " << vec.size() << std::endl << std::endl;
}

template <class T>
void	relation(T const & foo, T const & bar, int & i)
{
	std::cout << "------check " << ++i << "------" << std::endl;
	std::cout << "foo == bar = " << (foo == bar ? "true" : "false") << std::endl;
	std::cout << "foo != bar = " << (foo != bar ? "true" : "false") << std::endl;
	std::cout << "foo < bar  = " << (foo <  bar ? "true" : "false") << std::endl;
	std::cout << "foo > bar  = " << (foo >  bar ? "true" : "false") << std::endl;
	std::cout << "foo <= bar = " << (foo <= bar ? "true" : "false") << std::endl;
	std::cout << "foo >= bar = " << (foo >= bar ? "true" : "false") << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << std::endl;
}

template <typename T>
bool isConst(T& x)
{
	static_cast<void>(x);
	return false;
}

template <typename T>
bool isConst(T const & x)
{
	static_cast<void>(x);
	return true;
}

void	constructor( void );
void	all_it( void );
void	capacity_test( void );
void	modifiers( void );
void	element_access( void );
void	relation_op( void );

#endif
