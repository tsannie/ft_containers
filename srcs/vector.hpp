/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 09:39:39 by tsannie           #+#    #+#             */
/*   Updated: 2021/10/19 13:11:31 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <memory>
#include <iostream>

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

	typedef	T										value_type;
	typedef	Allocator								allocator_type;
	typedef	size_t									size_type;
	typedef	ptrdiff_t								difference_type;
	typedef	value_type&								reference;
	typedef	const value_type&						const_reference;
	typedef	typename Allocator::pointer				pointer;
	typedef	typename Allocator::const_pointer		const_pointer;
	//typedef	LegacyRandomAccessIterator	iterator;
	//typedef	const_LegacyRandomAccessIterator	const_iterator;
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
			std::cout << "ok" << std::endl;
		}
		~vector() {}

		iterator begin( void )
		{

		}


};

}

#endif
