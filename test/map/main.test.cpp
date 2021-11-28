/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:32:43 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/28 18:26:57 by tsannie          ###   ########.fr       */
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

	pl::map<int, int, comp> map;

	map[0] = 10;
	map[1] = 30;
	map[2] = 50;
	map[3] = 70;
	map[4] = 70;
	map[5] = 70;

	pl::map<int, int, comp>::iterator	it, end;

	end = map.begin();
	it = map.begin();
	--it;
	for (; it != end ; it--)
		std::cout << it->first << " => " << it->second << std::endl;
	std::cout << "size = " << map.size() << std::endl;
	std::cout << "----------------\n" << std::endl;


	//pac.erase(++pac.begin(), --pac.end());

	//printMap(pac, "pac");
}
