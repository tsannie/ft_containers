/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:32:43 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/28 07:12:48 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.test.hpp"


#define T1 int
#define T2 std::string
typedef pl::pair<const T1, T2> T3;

int	main( void )
{
	/*constructor();
	all_it();
	capacity_test();
	element_access();
	modifiers();
	observers();
	operations();
	relation_op();*/

	ft::map<int, int> pac;

	pac[0] = 10;
	pac[1] = 30;
	pac[2] = 50;
	pac[3] = 70;
	pac[4] = 70;
	pac[5] = 70;

	printMap(pac, "pac");

	std::cout << "1" << std::endl;
	pac.erase(1);
	printMap(pac, "pac");
	std::cout << "2" << std::endl;
	pac.erase(2);
	printMap(pac, "pac");
	std::cout << "3" << std::endl;
	pac.erase(3);
	printMap(pac, "pac");
	std::cout << "4" << std::endl;
	pac.erase(4);
	printMap(pac, "pac");
	std::cout << "5" << std::endl;
	pac.erase(5);
	printMap(pac, "pac");

	//pac.erase(++pac.begin(), --pac.end());

	//printMap(pac, "pac");
}
