/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.test.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:20:07 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/25 18:14:30 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.test.hpp"

void	constructor( void )
{
	std::cout << "test constructor :" << std::endl;
	pl::vector<int>	vec(50,42);

	pl::stack<int>	first;							// empty
	pl::stack<int, pl::vector<int> > second;		// empty stack using vector
	pl::stack<int, pl::vector<int> > third(vec);	// copy vector

	std::cout << "size first  = " << first.size() << '\n';
	std::cout << "size second = " << second.size() << '\n';
	std::cout << "size third  = " << third.size() << '\n';
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}
