/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:39:26 by tsannie           #+#    #+#             */
/*   Updated: 2021/10/25 16:04:42 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iostream>
#include <memory>
#include "../includes/iterator.hpp"

namespace ft
{

template<typename T,
typename Category,
bool isConst = false
> class iterator
{

public:
	typedef	Category		iterator_category;
	typedef	T				value_type;
	typedef	std::ptrdiff_t	difference_type;
	typedef	T*				pointer;
	typedef	T&				reference;

private:
	value_type*		_val;

public:

	iterator( void ): _val( NULL ) {}
	explicit iterator( pointer val ): _val( val ) {}
	iterator( iterator const &cpy ) { *this = cpy; }

	operator iterator<const T, Category, true>() const
	{
		return iterator<const T, Category, true> (this->_val);
	}

	iterator&	operator=( iterator const &rhs )
	{
		if ( this != &rhs )
			this->_val = rhs.getVal();
		return (*this);
	}

	iterator&	operator++( void )
	{
		this->_val++;
		return (*this);
	}

	iterator	operator++( int )
	{
		iterator	cpy = *this;
		this->_val++;
		return (cpy);
	}

	bool		operator==( iterator<T, Category, false> const &b ) const
	{
		return (this->_val == b.getVal());
	}

	bool		operator!=( iterator<T, Category, false> const &b ) const
	{
		return (this->_val != b.getVal());
	}

	bool		operator<( iterator<T, Category, false> const &b ) const
	{
		return (this->_val < b.getVal());
	}

	bool		operator>( iterator<T, Category, false> const &b ) const
	{
		return (this->_val > b.getVal());
	}

	bool		operator<=( iterator<T, Category, false> const &b ) const
	{
		return (this->_val <= b.getVal());
	}

	bool		operator>=( iterator<T, Category, false> const &b ) const
	{
		return (this->_val >= b.getVal());
	}

	bool		operator==( iterator<T const, Category, true> const &b ) const
	{
		return (this->_val == b.getVal());
	}

	bool		operator!=( iterator<T const, Category, true> const &b ) const
	{
		return (this->_val != b.getVal());
	}

	bool		operator<( iterator<T const, Category, true> const &b ) const
	{
		return (this->_val < b.getVal());
	}

	bool		operator>( iterator<T const, Category, true> const &b ) const
	{
		return (this->_val > b.getVal());
	}

	bool		operator<=( iterator<T const, Category, true> const &b ) const
	{
		return (this->_val <= b.getVal());
	}

	bool		operator>=( iterator<T const, Category, true> const &b ) const
	{
		return (this->_val >= b.getVal());
	}

	iterator&	operator--( void )
	{
		this->_val--;
		return (*this);
	}

	iterator	operator--( int )
	{
		iterator	cpy = *this;
		this->_val--;
		return (cpy);
	}

	reference	operator[]( difference_type b ) const
	{
		return (this->_val[b]);
	}

	value_type&	operator*( void ) const { return (*this->_val); }

	pointer		operator->( void ) const { return (this->_val); }

	iterator	operator+( difference_type const &b ) const
	{
		return (iterator(this->_val + b));
	}

	iterator	operator-( difference_type const &b ) const
	{
		return (iterator(this->_val - b));
	}

	difference_type	operator-( iterator<T, Category, false> const & x ) const
	{
		return (this->_val - x.getVal());
	}

	difference_type	operator-( iterator<T const, Category, true> const & x) const
	{
		return (this->_val - x.getVal());
	}

	iterator&	operator+=( difference_type n )
	{
		_val += n;
		return (*this);
	}

	iterator&	operator-=( difference_type n )
	{
		_val -= n;
		return (*this);
	}

	value_type*	getVal( void ) const { return (this->_val); }

};

template<
typename T,
typename Category,
bool isConst
> iterator<T, Category, isConst>	operator+(
	const typename iterator<T, Category, isConst>::difference_type &b,
	const iterator<T, Category, isConst> &rhs )
{
	return (iterator<T, Category, isConst>(rhs + b));
}

}


#endif
