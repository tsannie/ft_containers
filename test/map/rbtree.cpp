/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:14:37 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/06 20:45:31 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/RBTrees.hpp"

int	main(void)
{
	ft::RbTrees<int, char>		test;

	test.insertNode(0, 'a');
	test.insertNode(1, 'b');
	test.insertNode(-1, 'c');
	test.insertNode(2, 'd');
	test.deleteNode(2);

	test.searchNode(2);


	test.printTree();
}
