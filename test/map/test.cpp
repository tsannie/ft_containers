/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:06:31 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/03 20:19:31 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <stack>
#include <vector>
#include <list>
#include <map>
#include "../../map.hpp"


int		main(void)
{
	std::map<char,int> first;

	first.insert( std::pair<char,int>('a',100) );
	first.insert( std::pair<char,int>('b',200) );
	first.insert( std::pair<char,int>('c',300) );

	for (std::map<char,int>::iterator it = first.begin(); it != first.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	/*first.push(61);
	first.push(62);*/

	/*cmp(stck, stck2); // 1


	cmp(stck, stck2); // 2
	cmp(stck2, stck); // 3

	stck.push(42);

	cmp(stck, stck2); // 4
	cmp(stck2, stck); // 5

	stck.push(100);

	cmp(stck, stck2); // 6
	cmp(stck2, stck); // 7*/
	return (0);
}
