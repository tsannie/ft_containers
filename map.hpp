/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:51:38 by tsannie           #+#    #+#             */
/*   Updated: 2021/10/28 17:09:29 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include <memory>
#include <cstddef>
#include <iostream>
#include "includes/iterator.hpp"
#include "includes/algorithm.hpp"
#include "includes/string.hpp"
#include "includes/type_traits.hpp"
#include "includes/utility.hpp"


namespace ft
{
template <class Key,
		class T,
		class Compare = std::less<Key>,
		class Alloc = std::allocator<ft::pair<const Key,T> >
> class map
{

template <class Key, class T, class Compare, class Alloc>
class map<Key,T,Compare,Alloc>::value_compare
{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
  friend class map;
protected:
  Compare comp;
  value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
public:
  typedef bool result_type;
  typedef value_type first_argument_type;
  typedef value_type second_argument_type;
  bool operator() (const value_type& x, const value_type& y) const
  {
    return comp(x.first, y.first);
  }
}

public:
	typedef				Key										key_type;
	typedef				T										mapped_type;
	typedef				ft::pair<const key_type,mapped_type>	value_type;
	typedef				Compare									key_compare;
	//typedef			Compare	value_compare;
	typedef				Alloc									allocator_type;
	typedef typename	allocator_type::reference				reference;
	typedef typename	allocator_type::const_reference			const_reference;
	typedef typename	allocator_type::pointer					pointer;
	typedef typename	allocator_type::const_pointer			const_pointer;
	typedef				ptrdiff_t								difference_type;
	typedef				size_t									size_type;



private:
	/* data */

public:

	explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
	{
	}

	~map();
};

}
#endif
