/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTrees.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:07:59 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/01 18:07:16 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTREES_HPP
# define RBTREES_HPP

#include <iostream>

#define	BLACK	false
#define	RED		true


namespace ft
{

template<class Key, class Value>
class RbTrees
{

private:

	typedef	enum color_t { BLACK, RED }	Color;

	typedef struct	s_node {
		struct s_node*	parent;
		struct s_node*	left; // left = 0 ; right = 1
		struct s_node*	right; // left = 0 ; right = 1
		Color			color;
		Key				key;
		Value			value;
	}				node;

	node	*test;

public:

};

}

#endif
