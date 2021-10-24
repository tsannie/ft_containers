/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:39:26 by tsannie           #+#    #+#             */
/*   Updated: 2021/10/24 01:32:20 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iostream>
#include <memory>
#include "../includes/iterator.hpp"

namespace ft
{

template<typename T, typename Category, bool isConst = false>
class iterator
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
	/*   ALL CATEGORIES   */

	iterator( void ): _val( NULL ) {}
	explicit iterator( pointer val ): _val( val ) {}
	iterator( iterator const &cpy ) { *this = cpy; }

	iterator&	operator=( iterator const &rhs )
	{
		if ( this != &rhs )
			this->_val = rhs._val;
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

	/*   INPUT   */


	bool		operator==( const iterator<T, Category, false> &rhs ) const
	{
		return (rhs._val == this->_val);
	}

	bool		operator!=( const iterator<T, Category, false> &rhs ) const
	{
		return (rhs._val != this->_val);
	}

	value_type&	operator*( void ) { return (*this->_val); }

	pointer*	operator->( void ) { return (this->_val); }


	/*   OUTPUT   */
	// ??


	/*   FORWARD   */
	// ??


	/*   BIDIRECTIONAL   */

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

	/*   RANDOM ACCESS   */


	iterator	operator+( const difference_type &b ) const
	{
		return (iterator(this->_val + b));
	}

	iterator	operator-( const difference_type &b ) const
	{
		return (iterator(this->_val - b));
	}
	difference_type	operator-	(const iterator & x) const
	{
		return (this->_val - x._val);
	}

	bool operator<(const iterator &b) const { return (this->_val < b._val); }

	bool operator>(const iterator &b) const { return (this->_val > b._val); }

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

template<
typename T,
typename Category,
bool isConst
> iterator<T, Category, isConst>	operator-(
	const typename iterator<T, Category, isConst>::difference_type &b,
	const iterator<T, Category, isConst> &rhs)
{
	return (iterator<T, Category, isConst>(rhs - b));
}

}


#endif
