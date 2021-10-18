/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 10:07:56 by tsannie           #+#    #+#             */
/*   Updated: 2021/10/18 10:09:33 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include <deque.hpp>

template<
    class T,
    class Container = std::deque<T>
> class stack;
class stack
{
public:
	stack(/* args */);
	~stack();
private:
	/* data */
};



#endif
