/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:14:37 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/02 22:32:56 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/RBTrees.hpp"

int	main(void)
{
	ft::RbTrees<int, char>		test;

	test.insertNode(0, 'a');
	test.insertNode(0, 'b');
	test.insertNode(0, 'c');
	test.insertNode(0, 'd');

	test.printTree();
}
