/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:51:24 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/26 15:34:22 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

void	test1()
{
	std::cout << "********************************************************************************" << std::endl;
	try
	{
		Span sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.printContainer();
		std::cout << "ShortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "LongestSpan: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "********************************************************************************" << std::endl << std::endl;
}

void	testContainerOverflow()
{
	std::cout << "********************************************************************************" << std::endl;
	try
	{
		Span sp = Span(5);
		
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(19);
		sp.printContainer();
		std::cout << "ShortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "LongestSpan: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "********************************************************************************" << std::endl << std::endl;
}

void	testContainerIsNotFullEnough()
{
	std::cout << "********************************************************************************" << std::endl;
	try
	{
		Span sp = Span(1);
		
		sp.addNumber(6);
		sp.printContainer();
		std::cout << "ShortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "LongestSpan: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "********************************************************************************" << std::endl << std::endl;
}

void	testRangeIterator()
{
	std::cout << "********************************************************************************" << std::endl;
	try
	{
		Span sp = Span(5);
		std::vector<int>	vec;

		for (int i = 0; i < 10000; i++)
		{
			vec.push_back(i + 1);
		}
		sp.addNumber(vec.begin(), vec.end());
		sp.printContainer();
		std::cout << "ShortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "LongestSpan: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "********************************************************************************" << std::endl << std::endl;
}

int	main(void)
{
	test1();
	testContainerOverflow();
	testContainerIsNotFullEnough();
	// testRangeIterator();
	return (0);
}