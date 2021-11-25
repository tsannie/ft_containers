/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.test.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:53:36 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/25 18:11:29 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TEST_HPP
# define STACK_TEST_HPP

#include <iostream>
#include <ostream>
#include <stack>
#include <vector>
#include <set>
#include "../../stack.hpp"
#include "../../vector.hpp"

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
void	methods( void );
void	relation_op( void );

#endif
