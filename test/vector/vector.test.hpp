/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.test.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:53:36 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/24 15:16:26 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_TEST_HPP
# define VECTOR_TEST_HPP

#include <iostream>
#include <ostream>
#include <vector>
#include <set>
#include "../../vector.hpp"

#ifndef pl
# define pl ft
#endif

template <typename T>
void printVec(T &vec)
{
	typename T::iterator it;
	typename T::iterator end;

	std::cout << "[ ";
	end = vec.end();
	for (it = vec.begin() ; it != end ; it++)
		std::cout << *it << " ";
	std::cout << "]" << std::endl;
	std::cout << "capacity = " << vec.capacity() << std::endl;
	std::cout << "size = " << vec.size() << std::endl << std::endl;
}

#endif
