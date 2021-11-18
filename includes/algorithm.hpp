/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:28:43 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/18 14:28:12 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_HPP
# define ALGORITHM_HPP

namespace ft
{

template <class T>
void swap ( T& a, T& b )
{
	T	tmp(a);

	a = b;
	b = tmp;
}

template<class InputIterator1, class InputIterator2>
bool	equal( InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
{
	while (first1 != last1)
	{
		if (!(*first1 == *first2))
			return (false);
		++first1;
		++first2;
	}
	return (true);
}

template<class InputIterator1, class InputIterator2>
bool	lexicographical_compare( InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2 )
{
	while (first1 != last1)
	{
		if (first2 == last2 || *first2 < *first1)
			return (false);
		else if (*first1 < *first2)
			return (true);
		++first1;
		++first2;
	}
	return (first2 != last2);
}

}

#endif
