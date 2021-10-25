/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:19:24 by tsannie           #+#    #+#             */
/*   Updated: 2021/10/25 21:25:20 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_HPP
# define STRING_HPP

#include <iostream>
#include <sstream>
#include <string>

namespace ft
{

template<typename T>
std::string	to_string(T str)
{
	std::ostringstream	buf;

	buf << str;
	return (buf.str());
}

}

#endif
