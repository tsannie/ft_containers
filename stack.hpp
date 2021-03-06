/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:07:56 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/29 10:40:41 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "includes/stl.hpp"

namespace ft
{

template<
	class T,
	class Container = ft::vector<T>
> class stack
{

public:

	/*   Member Types   */
	typedef				Container					container_type;
	typedef typename	Container::value_type		value_type;
	typedef typename	Container::size_type		size_type;
	typedef typename	Container::reference		reference;
	typedef typename	Container::const_reference	const_reference;

private:
	Container _ctnr;

public:
	/*   Constructors   */
	explicit			stack( container_type const &
							ctnr = container_type() ): _ctnr(ctnr) {}

	/*   Destructor   */
	~stack() {}

	/*   Member functions   */
	bool				empty( void ) const
	{
		return (this->_ctnr.empty());
	}

	size_type			size( void ) const
	{
		return (this->_ctnr.size());
	}

	value_type&			top( void )
	{
		return (this->_ctnr.back());
	}

	value_type const &	top( void ) const
	{
		return (this->_ctnr.back());
	}

	void				push ( value_type const & val )
	{
		return (this->_ctnr.push_back(val));
	}

	void				pop( void )
	{
		return (this->_ctnr.pop_back());
	}

	/*   Relational Operators   */
	friend bool	operator==( stack<T, Container> const & lhs, stack<T, Container> const & rhs)
	{
		return (lhs._ctnr == rhs._ctnr);
	}

	friend bool	operator!=( stack<T, Container> const & lhs, stack<T, Container> const & rhs)
	{
		return (!(lhs == rhs));
	}

	friend bool	operator<( stack<T, Container> const & lhs, stack<T, Container> const & rhs)
	{
		return (lhs._ctnr < rhs._ctnr);
	}

	friend bool	operator<=( stack<T, Container> const & lhs, stack<T, Container> const & rhs)
	{
		return ((lhs < rhs) || (lhs == rhs));
	}

	friend bool	operator>( stack<T, Container> const & lhs, stack<T, Container> const & rhs)
	{
		return (rhs < lhs);
	}

	friend bool	operator>=( stack<T, Container> const & lhs, stack<T, Container> const & rhs)
	{
		return ((lhs > rhs) || (lhs == rhs));
	}
};

}


#endif
