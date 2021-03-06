/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.test.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:52:33 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/27 03:25:02 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.test.hpp"

void	constructor( void )
{
	std::cout << "test constructor :" << std::endl;
	pl::vector<int>	first;                                // default
	pl::vector<int>	second(4,100);                        // four ints with value 100
	pl::vector<int> third(second.begin(),second.end());   // iterating
	pl::vector<int> fourth(third);                        // copy
	pl::vector<int> five = third;                         // operator=

	std::cout << "------------------------------------" << std::endl;
	std::cout << "first :" << std::endl;
	printVec(first);
	std::cout << "------------------------------------" << std::endl;
	std::cout << "second :" << std::endl;
	printVec(second);
	std::cout << "------------------------------------" << std::endl;
	std::cout << "third :" << std::endl;
	printVec(third);
	std::cout << "------------------------------------" << std::endl;
	std::cout << "fourth :" << std::endl;
	printVec(fourth);
	std::cout << "------------------------------------" << std::endl;
	std::cout << "five :" << std::endl;
	printVec(five);
	std::cout << "------------------------------------------" << std::endl;
	std::cout << std::endl;
}
