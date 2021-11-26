/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.test.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:53:36 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/26 12:19:13 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_TEST_HPP
# define SET_TEST_HPP

#include <iostream>
#include <ostream>
#include <stack>
#include <vector>
#include <set>
#include "../../stack.hpp"
#include "../../vector.hpp"
#include "../../set.hpp"

#ifndef pl
# define pl ft
#endif

struct comp
{
	bool	operator()(const char& lhs, const char& rhs) const
	{
		return (lhs > rhs);
	}
};

template <typename T>
void checkRet(T & ret)
{
	if (ret.second)
		std::cout << *(ret.first) << " has been insert.";
	else
		std::cout << *(ret.first) << " already exist.";
	std::cout << std::endl;
}

template <typename T>
void printSet(T & set, std::string const & name)
{
	typename T::iterator it;
	typename T::iterator end;

	std::cout << "[ ";
	end = set.end();
	for (it = set.begin() ; it != end ; it++)
		std::cout << *it << " ";
	std::cout << "]" << std::endl;
	std::cout << "size = " << set.size() << std::endl << std::endl;
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

template <class T>
void	equals(T const & foo, T const & bar, int & i)
{
	std::cout << "------check " << ++i << "------" << std::endl;
	std::cout << "foo == bar = " << (foo == bar ? "true" : "false") << std::endl;
	std::cout << "foo != bar = " << (foo != bar ? "true" : "false") << std::endl;
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
void	observers( void );
void	operations( void );
void	relation_op( void );

#endif
