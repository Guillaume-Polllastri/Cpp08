/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 09:37:20 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/25 15:50:09 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>

void	testInTheContainer(std::vector<int>& v)
{
	try
	{
		easyfind(v, 4);
		std::cout << "Present dans le containe !" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Non trouve dans le container !" << std::endl;
	}
}

void	testNotInTheContainer(std::vector<int>& v)
{
	try
	{
		easyfind(v, 42);
		std::cout << "Present dans le containe !" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Non trouve dans le container !" << std::endl;
	}
}

int	main(void)
{
	std::vector<int> v;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	testInTheContainer(v);
	testNotInTheContainer(v);
	return 0;
}