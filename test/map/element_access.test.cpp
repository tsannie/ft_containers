/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_access.test.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 07:09:14 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/25 12:41:43 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.test.hpp"

void	op_access( void )
{
	pl::map<char, std::string> mymap;

	mymap['a'] = "an element";
	mymap['b'] = "another element";
	mymap['c'] = mymap['b'];

	std::cout << "mymap['a'] is " << mymap['a'] << std::endl;
	std::cout << "mymap['b'] is " << mymap['b'] << std::endl;
	std::cout << "mymap['c'] is " << mymap['c'] << std::endl;
	std::cout << "mymap['d'] is " << mymap['d'] << std::endl;

	printMap(mymap, "mymap");
}

void	element_access( void )
{
	op_access();
}
