/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:39:26 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/23 04:27:37 by tsannie          ###   ########.fr       */
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

protected:
	iterator_type	_it;

private:

public:

	reverse_iterator(): _it( Iterator() ) {}

	explicit reverse_iterator( iterator_type it ): _it(it) {}

	template<class Iter>
	reverse_iterator( reverse_iterator<Iter> const & rev_it ):
		_it(rev_it.base()) {}

	iterator_type		getIt( void ) const { return (this->_it); }

	iterator_type		base( void ) const {
			return (this->_it);
		}

	reference			operator*( void ) const
	{
		Iterator tmp = this->_it;

		return (*(--tmp));
	}

	reverse_iterator	operator+( difference_type n ) const
	{
		return (reverse_iterator(this->_it - n));
	}

	reverse_iterator&	operator++( void )
	{
		--this->_it;
		return (*this);
	}

	reverse_iterator	operator++( int )
	{
		reverse_iterator	ret(*this);
		--this->_it;
		return (ret);
	}

	reverse_iterator&	operator+=( difference_type n )
	{
		this->_it -= n;
		return (*this);
	}

	reverse_iterator	operator-( difference_type n ) const
	{
		return (reverse_iterator(this->_it + n));
	}

	reverse_iterator&	operator--( void )
	{
		++this->_it;
		return (*this);
	}

	reverse_iterator	operator--( int )
	{
		reverse_iterator	ret(*this);
		++this->_it;
		return (ret);
	}

	reverse_iterator&	operator-=( difference_type n )
	{
		this->_it += n;
		return (*this);
	}

	pointer operator->( void ) const { return (&(this->operator*())); }

	reference operator[] (difference_type n) const
	{
		return (*(this->_it + n));
	}

};

template<class Iter>
reverse_iterator<Iter> operator+(
	typename reverse_iterator<Iter>::difference_type n,
	reverse_iterator<Iter> const & rev_it )
{
	return (reverse_iterator<Iter>(rev_it.base() - n));
}

template<class It, class Ite>
typename reverse_iterator<It>::difference_type operator-(
	reverse_iterator<It> const & lhs,
	reverse_iterator<Ite> const & rhs)
{
	return (rhs.base() - lhs.base());
}

template<class It, class Ite>
bool	operator==(reverse_iterator<It> const & lhs,
				reverse_iterator<Ite> const & rhs)
{
	return (lhs.base() == rhs.base());
}

template<class It, class Ite>
bool	operator!=(reverse_iterator<It> const & lhs,
				reverse_iterator<Ite> const & rhs)
{
	return (lhs.base() != rhs.base());
}

template<class It, class Ite>
bool	operator<(reverse_iterator<It> const & lhs,
				reverse_iterator<Ite> const & rhs)
{
	return (lhs.base() > rhs.base());
}

template<class It, class Ite>
bool	operator<=(reverse_iterator<It> const & lhs,
				reverse_iterator<Ite> const & rhs)
{
	return (lhs.base() >= rhs.base());
}

template<class It, class Ite>
bool	operator>(reverse_iterator<It> const & lhs,
				reverse_iterator<Ite> const & rhs)
{
	return (lhs.base() < rhs.base());
}

template<class It, class Ite>
bool	operator>=(reverse_iterator<It> const & lhs,
				reverse_iterator<Ite> const & rhs)
{
	return (lhs.base() <= rhs.base());
}

}


#endif
