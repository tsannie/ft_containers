/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_access.test.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 07:09:14 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/26 10:21:38 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.test.hpp"

void	op_access( void )
{
	std::cout << "test op_access :" << std::endl;
	std::cout << std::endl;
	pl::map<char, std::string> mymap;

	mymap['a'] = "an element";
	mymap['b'] = "another element";
	mymap['c'] = mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << std::endl;
	std::cout << "mymap['b'] is " << mymap['b'] << std::endl;
	std::cout << "mymap['c'] is " << mymap['c'] << std::endl;
	std::cout << "mymap['d'] is " << mymap['d'] << std::endl;

	printMap(mymap, "mymap");
	std::cout << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}

void	element_access( void )
{
	op_access();
}
