/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relational_op.test.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:55:11 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/25 11:14:06 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.test.hpp"

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

int		main( void )
{
	int	i = 0;
	pl::vector<int> foo;   // three ints with a value of 100
	pl::vector<int> bar;   // two ints with a value of 200

	relation(foo, bar, i);

	foo.push_back(42);
	relation(foo, bar, i);

	bar.push_back(15);
	relation(foo, bar, i);

	return 0;
}
