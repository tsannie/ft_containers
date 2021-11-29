/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 14:51:38 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/29 10:30:29 by tsannie          ###   ########.fr       */
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
		class Alloc = std::allocator<ft::pair<const Key, T> >
> class map
{

public:

	/*   Member types   */
	typedef	Key										key_type;
	typedef	T										mapped_type;
	typedef	ft::pair<const key_type, mapped_type>	value_type;
	typedef	Compare									key_compare;

	class value_compare
	{
	protected:
		Compare comp;

	public:
		value_compare( Compare c ) : comp(c) {}
		typedef	bool		result_type;
		typedef	value_type	first_argument_type;
		typedef	value_type	second_argument_type;
		bool	operator()( value_type const & x,  value_type const & y) const
		{
			return comp(x.first, y.first);
		}
	};

	typedef				Alloc							allocator_type;
	typedef typename	allocator_type::reference		reference;
	typedef typename	allocator_type::const_reference	const_reference;
	typedef typename	allocator_type::pointer			pointer;
	typedef typename	allocator_type::const_pointer	const_pointer;

	typedef	ptrdiff_t												difference_type;
	typedef	size_t													size_type;
	typedef	ft::RBTreeMap<value_type, key_compare, allocator_type>	tree;

	typedef typename	tree::iterator					iterator;
	typedef typename	tree::const_iterator			const_iterator;
	typedef	typename	tree::reverse_iterator			reverse_iterator;
	typedef	typename	tree::const_reverse_iterator	const_reverse_iterator;

private:
	key_compare		_comp;
	allocator_type	_alloc;
	tree			_tree;


public:

	/*   Constructors   */
	explicit map ( key_compare const & comp = key_compare(),
				allocator_type const & alloc = allocator_type() )
	{
		this->_alloc = alloc;
		this->_comp = comp;
	}

	template <class InputIterator>
	map(InputIterator first, InputIterator last,
		key_compare const & comp = key_compare(),
		allocator_type const & alloc = allocator_type())
	{
		this->_alloc = alloc;
		this->_comp = comp;
		this->insert(first, last);
	}

	map( const map& rhs )
	{
		*this = rhs;
	}

	/*   Destructor   */
	~map() {}

	map&	operator=( map const & rhs )
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

	/*   Iterators   */
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

	/*   Capacity   */
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

	/*   Element Access   */
	mapped_type& operator[]( key_type const & k )
	{
		iterator	it;

		it = (this->insert( ft::make_pair(k, mapped_type()) )).first;
		return (it->second);
	}

	/*   Modifiers   */
	ft::pair<iterator, bool>	insert( value_type const & val )
	{
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

	void	erase( iterator position )
	{
		return (this->_tree.erase(position));
	}

	size_type	erase( key_type const & k )
	{
		return (this->_tree.erase(ft::make_pair(k, mapped_type())));
	}

	void	erase( iterator first, iterator last )
	{
		this->_tree.erase(first, last);
	}

	void	swap( map& x )
	{
		this->_tree.swap(x._tree);
	}

	void	clear( void )
	{
		this->_tree.clear();
	}

	/*   Observers   */
	key_compare	key_comp( void ) const
	{
		return (this->_comp);
	}

	value_compare	value_comp( void ) const
	{
		return (value_compare(this->_comp));
	}

	/*   Operations   */
	iterator	find( key_type const & k )
	{
		return (this->_tree.find(ft::make_pair(k, mapped_type())));
	}


	const_iterator	find( key_type const & k ) const
	{
		return (this->_tree.find(ft::make_pair(k, mapped_type())));
	}

	size_type	count( key_type const & k ) const
	{
		return (this->_tree.count(ft::make_pair(k, mapped_type())));
	}

	iterator	lower_bound( key_type const & k )
	{
		iterator	it;

		for (it = this->begin() ; it != this->end()
			&& this->_comp(it->first, k) ; ++it) {}
		return (it);
	}

	const_iterator	lower_bound( key_type const & k ) const
	{
		const_iterator	it;

		for (it = this->begin() ; it != this->end()
			&& this->_comp(it->first, k) ; ++it) {}
		return (it);
	}

	iterator	upper_bound( key_type const & k )
	{
		iterator	it;

		for (it = this->begin() ; it != this->end()
			&& this->_comp(k, it->first) == false; ++it) {}
		return (it);
	}

	const_iterator	upper_bound ( key_type const & k ) const
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

	/*   Allocator   */
	allocator_type	get_allocator( void ) const
	{
		return (this->_alloc);
	}
};

/*   Non-Member Function   */
template< class Key, class T, class Compare, class Alloc >
void swap( ft::map<Key,T,Compare,Alloc>& lhs,
			ft::map<Key,T,Compare,Alloc>& rhs )
{
	lhs.swap(rhs);
}

/*   Relational Operators   */
template< class Key, class T, class Compare, class Alloc >
bool operator==( ft::map<Key,T,Compare,Alloc> const & lhs,
				ft::map<Key,T,Compare,Alloc> const & rhs )
{
	if (lhs.size() != rhs.size())
		return (false);
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template< class Key, class T, class Compare, class Alloc >
bool operator!=( ft::map<Key,T,Compare,Alloc> const & lhs,
				ft::map<Key,T,Compare,Alloc> const & rhs )
{
	return (!(lhs == rhs));
}

template< class Key, class T, class Compare, class Alloc >
bool operator<( ft::map<Key,T,Compare,Alloc> const & lhs,
				ft::map<Key,T,Compare,Alloc> const & rhs )
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(),
										rhs.begin(), rhs.end()));
}

template< class Key, class T, class Compare, class Alloc >
bool operator<=( ft::map<Key,T,Compare,Alloc> const & lhs,
				ft::map<Key,T,Compare,Alloc> const & rhs )
{
	return ((lhs < rhs) || (lhs == rhs));
}

template< class Key, class T, class Compare, class Alloc >
bool operator>( ft::map<Key,T,Compare,Alloc> const & lhs,
				ft::map<Key,T,Compare,Alloc> const & rhs )
{
	return (rhs < lhs);
}

template< class Key, class T, class Compare, class Alloc >
bool operator>=( ft::map<Key,T,Compare,Alloc> const & lhs,
				ft::map<Key,T,Compare,Alloc> const & rhs )
{
	return ((lhs > rhs) || (lhs == rhs));
}


}
#endif
