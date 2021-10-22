/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 09:39:39 by tsannie           #+#    #+#             */
/*   Updated: 2021/10/22 21:26:36 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>
#include "../includes/iterator.hpp"

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
		this->_tab = this->alloc.allocate(n);
		this->size = n;
		this->capacity = 0;
		for (size_type i = 0 ; i < n ; i++)
			this->_alloc.construct(this->_tab + i, val);
	}

	~vector() {}

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
			else
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
			this->_alloc.deallocate(this->_tab, this->_capacity);
			this->_capacity = n;
			this->_tab = ret;
		}
	}

	/*   ELEMENT ACCESS   */
	reference operator[]( size_type n ) { return ( this->_tab[n] ); }
	const_reference operator[](size_type n) const { return ( this->_tab[n] ); }

	/*   MODIFIERS   */

	//template <class InputIterator>
	//void assign (InputIterator first, InputIterator last);

	//void assign (size_type n, const value_type& val);

	void push_back ( const value_type& val )
	{
		if (this->capacity() == 0)
			this->reserve(1);
		else if (this->size() == this->capacity())
			this->reserve(this->capacity() * 2);
		this->_alloc.construct(this->_tab + this->_size, val);
		this->_size++;
	}

	void pop_back( void )
	{
		this->_size--;
		std::cout << "size = " << this->size() << std::endl;
		this->_alloc.destroy(this->_tab + this->size());
	}

	iterator insert ( iterator position, const value_type& val )
	{
		ft::vector<int>::iterator	it;
		ft::vector<int>::iterator	end;


		for (it = this->begin() ; it != position ; it++)


		return ();
	}


	void insert ( iterator position, size_type n, const value_type& val ) {}
	{

	}

	/* template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last) {}
	{

	}*/
};

}

#endif
