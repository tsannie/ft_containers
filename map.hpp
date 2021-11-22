/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:51:38 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/22 10:06:42 by tsannie          ###   ########.fr       */
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
	public:
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
	typedef	ft::RBTree<value_type, key_compare, allocator_type>		tree;

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

	template <class InputIterator>
	map(InputIterator first, InputIterator last,
		const key_compare& comp = key_compare(),
		const allocator_type& alloc = allocator_type())
	{
		this->_alloc = alloc;
		this->_comp = comp;
		this->insert(first, last);
	}

	map( const map& rhs )
	{
		*this = rhs;
	}

	~map() {}


	map&	operator=( const map& rhs )
	{
		if (this != &rhs)
		{
			this->_tree.clear();
			this->_alloc = rhs._alloc;
			this->_comp = rhs._comp;
			this->insert(rhs.begin(), rhs.end());
		}
		return (*this);
	}

	// Iterators:

	iterator	begin( void )
	{
		return (this->_tree.begin());
	}

	const_iterator	begin( void ) const
	{
		return (this->_tree.begin());
	}

	iterator	end( void )
	{
		return (this->_tree.end());
	}

	const_iterator	end( void ) const
	{
		return (this->_tree.end());
	}

	reverse_iterator	rbegin( void )
	{
		return (this->_tree.rbegin());
	}

	const_reverse_iterator	rbegin( void ) const
	{
		return (this->_tree.rbegin());
	}

	reverse_iterator	rend( void )
	{
		return (this->_tree.rend());
	}

	const_reverse_iterator	rend( void ) const
	{
		return (this->_tree.rend());
	}


	// Capacity:

	bool	empty( void ) const
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

	mapped_type& operator[](const key_type& k)
	{
		iterator	it;
		mapped_type	x;


		it = (this->insert( ft::make_pair(k, x) )).first;
		return (it->second);
	}

	// Modifiers:

	ft::pair<iterator, bool>	insert( value_type const & val )
	{
		//std::cout << "insert" << std::endl;
		return (this->_tree.insert(val));
	}

	iterator	insert( iterator position, value_type const & val )
	{
		return (this->_tree.insert(position, val));
	}

	template <class InputIterator>
	void	insert( InputIterator first, InputIterator last )
	{
		this->_tree.insert(first, last);
	}

	void	erase(iterator position)
	{
		return (this->_tree.erase(position));
	}

	size_type	erase( key_type const & k )
	{
		mapped_type	x;

		return (this->_tree.erase(ft::make_pair(k, x)));
	}

	void	erase( iterator first, iterator last )
	{
		//std::cout << first->first << " => " << first->second << '\n';
		//std::cout << last->first << " => " << last->second << '\n';
		this->_tree.erase(first, last);
	}

	void	swap(map& x)
	{
		ft::swap(*this, x);
	}

	void	clear( void )
	{
		this->_tree.clear();
	}

	// Observers:

	key_compare	key_comp( void ) const
	{
		return (this->_comp);
	}

	value_compare	value_comp( void ) const
	{
		return (value_compare(this->_comp));
	}

	// Operations:

	iterator	find( key_type const & k )
	{
		mapped_type	x;

		return (this->_tree.find(ft::make_pair(k, x)));
	}


	const_iterator	find( key_type const & k ) const
	{
		mapped_type	x;

		return (this->_tree.find(ft::make_pair(k, x)));
	}

	size_type	count(const key_type& k) const
	{
		mapped_type	x;

		return (this->_tree.count(ft::make_pair(k, x)));
	}

	iterator	lower_bound( key_type const & k )
	{
		iterator	it;

		for (it = this->begin() ; it != this->end()
			&& this->_comp(it->first, k) ; ++it) {}
		return (it);
	}

	const_iterator lower_bound( key_type const & k ) const
	{
		const_iterator	it;

		for (it = this->begin() ; it != this->end()
			&& this->_comp(it->first, k) ; ++it) {}
		return (it);
	}

	iterator upper_bound (const key_type& k)
	{
		iterator	it;

		for (it = this->begin() ; it != this->end()
			&& this->_comp(k, it->first) == false; ++it) {}
		return (it);
	}

	const_iterator upper_bound (const key_type& k) const
	{
		const_iterator	it;

		for (it = this->begin() ; it != this->end()
			&& this->_comp(k, it->first) == false; ++it) {}
		return (it);
	}

	pair<iterator ,iterator>	equal_range( key_type const & k )
	{
		return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
	}

	pair<const_iterator ,const_iterator>	equal_range( key_type const & k ) const
	{
		return (ft::make_pair(this->lower_bound(k), this->upper_bound(k)));
	}


};

}
#endif
