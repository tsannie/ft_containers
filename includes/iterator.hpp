/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:39:26 by tsannie           #+#    #+#             */
/*   Updated: 2021/10/19 15:28:44 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

#include <iostream>

namespace ft
{

template<
typename T,
typename Category,
bool isConst = false
> class iterator
{

	typedef	Category		iterator_category;
	typedef	T				value_type;
	typedef	std::ptrdiff_t	difference_type;
	typedef T* pointer;
	typedef T& reference;

	private:
		value_type*		_n;

	public:
		iterator( void ): _n( NULL ) {}
		iterator(iterator const & cpy) { *this = cpy; }
		~iterator( void );

		// = += -=

		iterator& operator=(iterator const & rhs)
		{
			if ( this != &rhs )
				this->_n = rhs._n;
			return (*this);
		}

		iterator&	operator+=	(difference_type n)
		{
			_ptr += n;
			return (*this);
		}

		iterator&	operator-=	(difference_type n)
		{
			_ptr -= n;
			return (*this);
		}

		// x++ x-- ++x --x

		iterator& operator++( void )
		{
			this->_n++;
			return (*this);
		}
		iterator& operator--( void )
		{
			this->_n--;
			return (*this);
		}

		iterator operator++(int)
		{
			iterator	cpy(*this);

			cpy._n++;
			return (cpy);
		}
		iterator operator--(int)
		{
			iterator	cpy(*this);

			cpy._n--;
			return (cpy);
		}
	};

}


#endif
