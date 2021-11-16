/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 15:10:07 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/16 22:00:27 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

namespace ft
{

template <class T1, class T2>
struct pair
{
	typedef	T1		first_type;
	typedef	T2		second_type;

	first_type	first;
	second_type	second;


	pair( void ): first(), second() {}

	template<class U, class V>
	pair( pair<U,V> const & pr ): first(pr.first), second(pr.second) {}

	pair( first_type const & a, second_type const & b ): first(a), second(b) {}

	pair& operator=( pair const & pr )
	{
		if (this != &pr)
		{
			first = pr.first;
			second = pr.second;
		}
		return (*this);
	}
};

template <class T1, class T2>
bool	operator==( pair<T1, T2> const & lhs, pair<T1, T2> const & rhs)
{
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template <class T1, class T2>
bool	operator!=( pair<T1, T2> const & lhs, pair<T1, T2> const & rhs)
{
	return (!(lhs == rhs));
}

template <class T1, class T2>
bool	operator<( pair<T1, T2> const & lhs, pair<T1, T2> const & rhs)
{
	return (lhs.first < rhs.first
		|| (!(rhs.first < lhs.first) && lhs.second < rhs.second));
}

template <class T1, class T2>
bool	operator<=( pair<T1, T2> const & lhs, pair<T1, T2> const & rhs)
{
	return (!(rhs < lhs));
}

template <class T1, class T2>
bool	operator>( pair<T1, T2> const & lhs, pair<T1, T2> const & rhs)
{
	return (rhs < lhs);
}

template <class T1, class T2>
bool	operator>=( pair<T1, T2> const & lhs, pair<T1, T2> const & rhs)
{
	return (!(lhs < rhs));
}

template <class T1,class T2>
ft::pair<T1,T2> make_pair(T1 x, T2 y)
{
	return ( ft::pair<T1,T2>(x,y) );
}

}

#endif
