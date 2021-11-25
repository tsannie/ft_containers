/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   relational_op.test.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:55:11 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/25 18:04:12 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.test.hpp"

void	relation_op( void )
{
	int	i = 0;
	pl::stack<int> foo;
	pl::stack<int> bar;

	relation(foo, bar, i);

	foo.push(42);
	relation(foo, bar, i);

	bar.push(41);
	relation(foo, bar, i);

	bar.push(43);
	relation(foo, bar, i);
}
