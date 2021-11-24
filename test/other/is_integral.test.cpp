/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.test.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 13:39:59 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/24 14:05:33 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/type_traits.hpp"
#include <type_traits>
#include <iostream>
#include <vector>

#define pl ft

class A {};

enum E : int {};

int main()
{
	// false
	std::cout << pl::is_integral<std::string>::value << '\n';
	std::cout << pl::is_integral<A>::value << '\n';
	std::cout << pl::is_integral<E>::value << '\n';
	std::cout << pl::is_integral<char *>::value << '\n';
	std::cout << pl::is_integral<int *>::value << '\n';
	std::cout << pl::is_integral<std::vector<int> >::value << '\n';

	// true
	std::cout << pl::is_integral<bool>::value << '\n';
	std::cout << pl::is_integral<unsigned char>::value << '\n';
	std::cout << pl::is_integral<int>::value << '\n';
	std::cout << pl::is_integral<const wchar_t>::value << '\n';
	std::cout << pl::is_integral<signed char>::value << '\n';
	std::cout << pl::is_integral<const signed char>::value << '\n';
}

