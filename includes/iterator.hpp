/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:39:26 by tsannie           #+#    #+#             */
/*   Updated: 2021/10/27 18:01:27 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iostream>
#include <memory>
#include "../includes/iterator.hpp"

namespace ft
{

template <class Iterator>
class reverse_iterator
{

public:
	typedef				Iterator						iterator_type;
	typedef typename	Iterator::difference_type		difference_type;
	typedef typename	Iterator::value_type			value_type;
	typedef typename	Iterator::pointer				pointer;
	typedef typename	Iterator::reference				reference;

private:
	iterator_type	_it;

public:

	reverse_iterator(): _it( Iterator() ) {}
	explicit reverse_iterator( iterator_type it ): _it(it) {}

	template <class Iter>
	reverse_iterator( reverse_iterator<Iter> const & rev_it )
	{
		this->_it = rev_it.base();
	}

	iterator_type		base( void ) const { return (this->_it); }

	reference			operator*( void ) const { return (*this->_it); }

	reverse_iterator	operator+( difference_type n ) const
	{
		return (vecIterator(this->_it - n));
	}

	reverse_iterator&	operator++( void )
	{
		this->_it--;
		return (*this);
	}

	reverse_iterator	operator++( int )
	{
		iterator_type	ret(*this);
		this->_it--;
		return (ret);
	}

	reverse_iterator&	operator+=( difference_type n )
	{
		this->_it -= n;
		return (*this);
	}

	reverse_iterator	operator-( difference_type n ) const
	{
		return (vecIterator(this->_it + n));
	}

	reverse_iterator&	operator--( void )
	{
		this->_it++;
		return (*this);
	}

	reverse_iterator	operator--( int )
	{
		iterator_type	ret(*this);
		this->_it++;
		return (ret);
	}

	reverse_iterator&	operator-=( difference_type n )
	{
		this->_it += n;
		return (*this);
	}

	pointer operator->( void ) const { return (this->_it); }

	reference operator[] (difference_type n) const { return (this->_it[n]); }

};

}


#endif
