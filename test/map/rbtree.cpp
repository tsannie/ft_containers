/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:14:37 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/22 11:20:22 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/RBTree.hpp"
#include "../../includes/utility.hpp"
#include "../../map.hpp"
#include <map>
#include <list>

#define	pl	ft

template <typename T>
void printVec(T &vec, std::string const & name)
{
	typename	T::iterator	it;
	typename	T::iterator	end;

	std::cout << name << " contains:" << std::endl;

	end = vec.end();
	for (it = vec.begin() ; it != end ; it++)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "size = " << vec.size() << std::endl;
	std::cout << "------------------------\n" << std::endl;
}

struct ft_more {
	bool	operator()(const int &first, const int &second) const {
		return (first > second);
	}
};

//typedef pl::map<int, std::string, ft_more>::iterator ft_mp_it;

int		main(void)
{
	pl::map<int, std::string, ft_more> mp;

	mp[12] = "no";
	mp[25] = "funny";
	mp[27] = "bee";
	mp[42] = "fgzgxfn";
	mp[80] = "hey";
	mp[90] = "8";
	printVec(mp, "mp");

	pl::map<int, std::string, ft_more>::iterator	it;
	pl::map<int, std::string, ft_more>::iterator	end;

	end = mp.end();
	for (it = mp.begin() ; it != end ; it++)
		std::cout << it->first << " => " << it->second << '\n';
	std::cout << "size = " << mp.size() << std::endl;
	std::cout << "------------------------\n" << std::endl;

	return (0);

}
