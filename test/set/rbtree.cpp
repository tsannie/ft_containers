/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:14:37 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/24 12:08:06 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utility.hpp"
#include "../../set.hpp"
#include <set>
#include <list>

#define	pl	std

template <typename T>
void printVec(T &vec, std::string const & name)
{
	typename	T::iterator	it;
	typename	T::iterator	end;

	std::cout << name << " contains:" << std::endl;

	end = vec.end();
	for (it = vec.begin() ; it != end ; it++)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "size = " << vec.size() << std::endl;
	std::cout << "------------------------\n" << std::endl;
}


#define T1 int

int		main(void)
{
	pl::set<T1> st;

	pl::set<T1>::iterator ite = st.begin();
	*ite = 42; // < -- error as well ; T is always const, even with regular iterator
	return (0);
}
