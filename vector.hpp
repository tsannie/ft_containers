/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 09:39:39 by tsannie           #+#    #+#             */
/*   Updated: 2021/10/27 00:22:11 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <cstddef>
#include <iostream>
#include "includes/iterator.hpp"
#include "includes/algorithm.hpp"
#include "includes/string.hpp"


namespace ft
{

template<
class T,
class Allocator = std::allocator<T>
> class vector
{


/****************/
/* Member types */
/****************/

public:
	typedef	T																value_type;
	typedef	Allocator														allocator_type;
	typedef	size_t															size_type;
	typedef	ptrdiff_t														difference_type;
	typedef	value_type&														reference;
	typedef	const value_type&												const_reference;
	typedef	typename Allocator::pointer										pointer;
	typedef	typename Allocator::const_pointer								const_pointer;
	typedef	ft::iterator<T, std::random_access_iterator_tag, false>			iterator;
	typedef	ft::iterator<T const, std::random_access_iterator_tag, true>	const_iterator;
	//typedef	std::reverse_iterator<iterator>			reverse_iterator;
	//typedef	std::reverse_iterator<const_iterator>	const_reverse_iterator;


private:
	allocator_type	_alloc;
	value_type		*_tab;
	size_type		_size;
	size_type		_capacity;


public:
	explicit vector (const allocator_type& alloc = allocator_type())
	{
		this->_alloc = alloc;
		this->_tab = this->_alloc.allocate(0);
		this->_size = 0;
		this->_capacity = 0;
	}

	explicit vector (size_type n, const value_type& val = value_type(),
		const allocator_type& alloc = allocator_type())
	{
		this->_alloc = alloc;
		this->_tab = NULL;
		this->_size = 0;
		this->_capacity = 0;
		this->resize(n, val);
	}

	template <class InputIterator>
	vector (InputIterator first, InputIterator last,
		const allocator_type& alloc = allocator_type())
	{
		std::cout << "*first\t=\t" << *first << std::endl;
		std::cout << "*last\t=\t" << *last << std::endl;
	}

	vector (const vector& x)
	{
		this->_alloc = x._alloc;
		this->_tab = this->_alloc.allocate(x.capacity());
		this->_capacity = x.capacity();
		this->_size = x.size();
		for (size_type i = 0 ; i < x.size() ; i++)
			this->_tab[i] = x._tab[i];
		this->_size = x._size;
	}

	~vector()
	{
		this->clear();
		this->_alloc.deallocate(this->_tab, this->_capacity);
	}

	vector& operator=( const vector& x )
	{
		if ( this != &x )
		{
			this->clear();
			this->reserve(x._size);
			for (size_type i = 0 ; i < x.size() ; i++)
				this->_alloc.construct(this->_tab + i, x[i]);
			this->_size = x.size();
		}
		return (*this);
	}

	/*   ITERATORS   */
	const_iterator	begin( void ) const
	{
		return (const_iterator(this->_tab));
	}

	iterator		begin( void )
	{
		return (iterator(this->_tab));
	}

	const_iterator	end( void ) const
	{
		return (const_iterator(this->_tab + this->_size));
	}

	iterator		end( void )
	{
		return (iterator(this->_tab + this->_size));
	}


	/*   CAPACITY   */

	size_type size( void ) const { return (this->_size); }

	size_type max_size( void ) const { return (this->_alloc.max_size()); }

	void resize(size_type n, value_type val = value_type())
	{
		if (n < this->size())
		{
			for (size_type i = n ; i < this->size() ; i++)
				this->_alloc.destroy(this->_tab + i);
			this->_size = n;
		}
		else if (n > this->size())
		{
			if (n > this->capacity() * 2)
				this->reserve(n);
			else if (n > this->capacity())
				this->reserve(this->capacity() * 2);
			for (size_type i = this->size() ; i < n ; i++)
			{
				this->_size++;
				this->_alloc.construct(this->_tab + i, val);
			}
		}
	}

	size_type capacity() const { return (this->_capacity); }

	bool empty() const { return (this->_size == 0); }

	void reserve(size_type n)
	{
		value_type	*ret;

		if (n > this->capacity())
		{
			ret = this->_alloc.allocate(n);
			for (size_type i = 0 ; i < this->size() ; i++)
			{
				this->_alloc.construct(ret + i, this->_tab[i]);
				this->_alloc.destroy(this->_tab + i);
			}
			if (this->_tab)
				this->_alloc.deallocate(this->_tab, this->_capacity);
			this->_capacity = n;
			this->_tab = ret;
		}
	}


	/*   ELEMENT ACCESS   */

	reference	operator[]( size_type n ) { return (this->_tab[n]); }

	const_reference	operator[]( size_type n ) const { return (this->_tab[n]); }

	reference	at( size_type n )
	{
		if (n >= this->size())
			throw std::out_of_range("vector::_M_range_check: __n (which is "
			+ ft::to_string(n) + ") >= this->size() (which is "
			+ ft::to_string(this->size()) + ")");
		return (this->_tab[n]);
	}

	const_reference	at( size_type n ) const
	{
		if (n >= this->size())
			throw std::out_of_range("vector::_M_range_check: __n (which is "
			+ ft::to_string(n) + ") >= this->size() (which is "
			+ ft::to_string(this->size()) + ")");
		return (this->_tab[n]);
	}

	reference	front( void ) { return (this->_tab[0]); }
	const_reference	front( void ) const { return (this->_tab[0]); }

	reference	back( void ) { return (this->_tab[this->size() - 1]); }
	const_reference	back( void ) const { return (this->_tab[this->size() - 1]); }

	/*   MODIFIERS   */

	/*template <class InputIterator>
	void assign (InputIterator first, InputIterator last)
	{

	}*/

	void	assign( size_type n, const value_type& val )
	{
		if (n > this->capacity())
			this->reserve(n);
		for (size_type i = 0 ; i < this->size() ; i++)
			this->_alloc.destroy(this->_tab + i);
		this->_size = n;
		for (size_type i = 0 ; i < n ; i++)
			this->_alloc.construct(this->_tab + i, val);

	}

	void	push_back( const value_type& val )
	{
		if (this->capacity() == 0)
			this->reserve(1);
		else if (this->size() == this->capacity())
			this->reserve(this->capacity() * 2);
		this->_alloc.construct(this->_tab + this->_size, val);
		this->_size++;
	}

	void	pop_back( void )
	{
		this->_size--;
		this->_alloc.destroy(this->_tab + this->size());
	}

	iterator	insert ( iterator position, const value_type& val )
	{
		this->insert(position, 1, val);
		return (iterator(this->begin() + (position - this->begin())));
	}


	void	insert( iterator position, size_type n, const value_type& val )
	{
		size_type	start = position - this->begin();

		if (n + this->size() > this->capacity() * 2)
			this->reserve(n + this->size());
		else if (n + this->size() > this->capacity())
			this->reserve(this->capacity() * 2);

		for (size_type i = this->size() + n ; i > this->size() ; i--)
			this->_alloc.construct(this->_tab + i - 1, this->_tab[i - n - 1]);
		for (size_type i = this->size() ; i >= start + n; i--)
			this->_tab[i] = this->_tab[i - n];
		for (size_type i = 0 ; i < n ; i++)
			this->_tab[start + i] = val;
		this->_size += n;
	}

	/* template <class InputIterator>
	void	insert (iterator position, InputIterator first, InputIterator last) {}
	{
	}*/

	iterator	erase( iterator position )
	{
		return (this->erase(position, position + 1));
	}

	iterator	erase( iterator first, iterator last )
	{
		size_type	start = first - this->begin();
		size_type	end = last - this->begin();
		size_type	i;

		for (i = start ; (i - start) + end < this->size() ; i++)
			this->_tab[i] = this->_tab[(i - start) + end];
		for (i = this->size() - end + start ; i < this->size() ; i++)
			this->_alloc.destroy(this->_tab + i);
		this->_size = this->size() - end + start;
		return (iterator(this->begin() + start));
	}

	void	swap( vector& x )
	{
		value_type		*tmp_tab = this->_tab;
		size_type		tmp_size = this->_size;
		size_type		tmp_capacity = this->_capacity;

		this->_tab = x._tab;
		this->_size = x._size;
		this->_capacity = x._capacity;
		x._tab = tmp_tab;
		x._size = tmp_size;
		x._capacity = tmp_capacity;
	}

	void	clear( void )
	{
		for (size_type i = 0 ; i < this->size() ; i++)
			this->_alloc.destroy(this->_tab + i);
		this->_size = 0;
	}

};


template <class T, class Alloc>
bool	operator==( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
{
	if (rhs.size() != lhs.size() || !ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
		return (false);
	return (true);
}

template <class T, class Alloc>
bool	operator!=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
{
	return (!(lhs == rhs));
}

template <class T, class Alloc>
bool	operator<( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
{
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}
template <class T, class Alloc>
bool	operator>( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
{
	return ((rhs < lhs));
}

template <class T, class Alloc>
bool	operator<=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
{
	return (!(rhs < lhs));
}


template <class T, class Alloc>
bool	operator>=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs )
{
	return (!(lhs < rhs));
}


}

#endif
