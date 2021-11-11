/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:14:37 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/11 10:50:46 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/RBTree.hpp"
#include "../../includes/utility.hpp"
#include "../../map.hpp"
#include <map>

#define	pl	ft

int	main(void)
{
	pl::map<int, char>	test;


	test.insert( pl::pair<int, char>(10, 'a') );
	test.insert( pl::pair<int, char>(20, 'c') );
	test.insert( pl::pair<int, char>(30, 'b') );
	test.insert( pl::pair<int, char>(40, 'd') );
	test.insert( pl::pair<int, char>(50, 'e') );

	pl::map<int, char>::iterator	it = test.begin();
	std::cout << it->first << "|" << it->second << std::endl;
	//test.deleteNode(2);

	//test.printTree();
}
