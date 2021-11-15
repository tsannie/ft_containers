/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:14:37 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/16 00:31:40 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/RBTree.hpp"
#include "../../includes/utility.hpp"
#include "../../map.hpp"
#include <map>

#define	pl	std

int	main(void)
{
	pl::map<int, char>	test;


	test.insert( pl::pair<int, char>(10, 'c') );

	pl::map<int, char>::iterator	it = test.begin();
	--it;
	--it;
	--it;
	--it;
	//std::cout << it->first << " => " << it->second << '\n';

	test.insert( pl::pair<int, char>(100, 'd') );
	test.insert( pl::pair<int, char>(20, 'c') );
	test.insert( pl::pair<int, char>(30, 'b') );
	test.insert( pl::pair<int, char>(40, 'd') );
	//std::cout << it->first << " => " << it->second << '\n';


	std::cout << it->first << " => " << it->second << '\n';
	for (it = test.begin(); it != test.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
	//test.deleteNode(2);

	//test.printTree();
}
