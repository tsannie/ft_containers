/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:51:38 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/09 17:47:41 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

#include "includes/stl.hpp"


namespace ft
{
template <class Key,
		class T,
		class Compare = std::less<Key>,
		class Alloc = std::allocator<ft::pair<const Key,T> >
> class map
{

public:
	typedef				Key										key_type;
	typedef				T										mapped_type;
	typedef				ft::pair<const key_type, mapped_type>	value_type;
	typedef				Compare									key_compare;

	class value_compare
	{
	protected:
		Compare comp;
		value_compare( Compare c ) : comp(c) {}

	public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;
		bool operator()(const value_type& x, const value_type& y) const
		{
			return comp(x.first, y.first);
		}
	};

	typedef				Alloc									allocator_type;
	typedef typename	allocator_type::reference				reference;
	typedef typename	allocator_type::const_reference			const_reference;
	typedef typename	allocator_type::pointer					pointer;
	typedef typename	allocator_type::const_pointer			const_pointer;

	//typedef	mapIterator<T, false>					iterator;
	//typedef	mapIterator<const T, true>				const_iterator;
	typedef	ft::reverse_iterator<iterator>			reverse_iterator;
	typedef	ft::reverse_iterator<const_iterator>	const_reverse_iterator;
	typedef	ptrdiff_t								difference_type;
	typedef	size_t									size_type;

private:
	key_compare								_comp;
	allocator_type							_alloc;
	ft::RBTree<key_type, mapped_type>		_tree;


public:

	explicit map (const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
	{
		this->_alloc = alloc;
		this->_comp = comp;
	}

	/*template <class InputIterator>
	map(InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type())
	{

	}*/

	map(const map& x)
	{}

	~map() {}

	/*map&	operator=(const map& x)
	{
		if (this != &x)
		{
			this->_alloc = x._alloc;
			this->_comp = x._comp;
		}
	}*/
};

}
#endif
