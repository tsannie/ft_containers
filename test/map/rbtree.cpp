/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:14:37 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/10 13:46:40 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/RBTree.hpp"
#include "../../includes/utility.hpp"
#include "../../map.hpp"
#include <map>

int	main(void)
{
	ft::map<int, char>	test;


	test.insert( ft::pair<int, char>(10, 'c') );
	//test.insert( ft::pair<int, char>(10, 'b') );
	//test.insert( ft::pair<int, char>(10, 'd') );
	//test.insert( ft::pair<int, char>(10, 'a') );
	//test.insert( ft::pair<int, char>(10, 'e') );

	//ft::map<int, char>::iterator	it;
	//test.deleteNode(2);

	//test.printTree();
}
