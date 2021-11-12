/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:14:37 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/12 14:14:50 by tsannie          ###   ########.fr       */
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
	test.insert( pl::pair<int, char>(20, 'c') );
	test.insert( pl::pair<int, char>(30, 'b') );
	test.insert( pl::pair<int, char>(40, 'd') );

	pl::map<int, char>::iterator	it = test.end();

	it--;
	std::cout << it->first << " => " << it->second << '\n';


	//for (pl::map<int, char>::iterator it = test.begin(); it != test.end(); ++it)
		//std::cout << it->first << " => " << it->second << '\n';
	//test.deleteNode(2);

	//test.printTree();
}
