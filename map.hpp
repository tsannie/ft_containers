/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:51:38 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/16 22:27:44 by tsannie          ###   ########.fr       */
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
		class Alloc = std::allocator<ft::pair<Key, T> >
> class map
{

public:
	typedef				Key										key_type;
	typedef				T										mapped_type;
	typedef				ft::pair<key_type, mapped_type>			value_type; //key is const ?
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


	typedef	ptrdiff_t												difference_type;
	typedef	size_t													size_type;
	typedef	ft::RBTree<value_type, allocator_type>					tree;

	typedef typename	tree::iterator					iterator;
	typedef typename	tree::const_iterator			const_iterator;
	typedef	typename	tree::reverse_iterator			reverse_iterator;
	typedef	typename	tree::const_reverse_iterator	const_reverse_iterator;

private:
	key_compare								_comp;
	allocator_type							_alloc;
	tree									_tree;


public:

	explicit map ( const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type() )
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

	map( const map& x )
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

	// Iterators:

	iterator	begin( void )
	{
		return (this->_tree.begin());
	}

	const_iterator	begin( void ) const
	{
		return (this->_tree.begin());
	}

	iterator end()
	{
		return (this->_tree.end());
	}

	const_iterator end() const
	{
		return (this->_tree.end());
	}

	reverse_iterator rbegin()
	{
		return (this->_tree.rbegin());
	}

	const_reverse_iterator rbegin() const
	{
		return (this->_tree.rbegin());
	}

	reverse_iterator rend()
	{
		return (this->_tree.rend());
	}

	const_reverse_iterator rend() const
	{
		return (this->_tree.rend());
	}


	// Capacity:

	bool empty( void ) const
	{
		return (this->_tree.empty());
	}

	size_type	size( void ) const
	{
		return (this->_tree.size());
	}

	size_type	max_size( void ) const
	{
		return (this->_tree.max_size());
	}

	// Element access:

	//mapped_type& operator[](const key_type& k);

	// Modifiers:

	ft::pair<iterator, bool>	insert( value_type const & val )
	{
		//std::cout << "insert" << std::endl;
		return (this->_tree.insert(val));
	}


	void	 erase(const key_type& k, const mapped_type& z)
	{
		this->_tree.deleteNode( ft::pair<key_type, mapped_type>(k, z) );
	}
};

}
#endif
