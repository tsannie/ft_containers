/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_access.test.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsannie <tsannie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 07:09:14 by tsannie           #+#    #+#             */
/*   Updated: 2021/11/25 07:54:23 by tsannie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.test.hpp"

void	op_access( void )
{
	pl::vector<int>	myvector(10, 42);

	printVec(myvector);
	for (int i = 0 ; i < myvector.capacity() ; i++)
		myvector[i] = i * 6;

	printVec(myvector);

	for (int i = 0 ; i < myvector.capacity() ; i++)
		std::cout << myvector[i] << " | ";
	std::cout << std::endl;

	for (int i = 0 ; i < 100 ; i++)
		myvector[i] = i * 3;

	printVec(myvector);
}

void	at( void )
{
	pl::vector<int>	myvector;

	myvector.reserve(100);
	std::cout << "SAKHBFDAHKBFADKKHDFAHKBFDAHAFHKD" << std::endl;


	/*printVec(myvector);
	for (int i = 0 ; i < myvector.capacity() ; i++)
		myvector.at(i) = i * 6;

	printVec(myvector);

	for (int i = 0 ; i < myvector.size() ; i++)
		std::cout << myvector.at(i) << " | ";
	std::cout << std::endl;*/

	//
	/*std::cout << "NOW DHJBSFDHBKDFSHBKSFDDFKS" << std::endl;
	printVec(myvector);
	for (int i =  myvector.size() ; i < (myvector.size() + 5) ; i++)
	{
		try
		{
			myvector.at(i);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}*/

	printVec(myvector);
}
int	main( void )
{
	op_access(); // []
	at();

	return 0;
}
