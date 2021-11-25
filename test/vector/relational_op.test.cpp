/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relational_op.test.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:55:11 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/25 11:39:22 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.test.hpp"

void	relation_op( void )
{
	int	i = 0;
	pl::vector<int> foo;
	pl::vector<int> bar;

	relation(foo, bar, i);

	bar.reserve(100);
	relation(foo, bar, i);

	foo.push_back(42);
	relation(foo, bar, i);

	bar.push_back(43);
	relation(foo, bar, i);

	bar.push_back(21);
	relation(foo, bar, i);
}