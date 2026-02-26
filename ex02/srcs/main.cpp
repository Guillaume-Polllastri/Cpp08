/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:50:42 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/26 19:30:10 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

void	classicTestMutantStack()
{
	std::cout << "********************************************************************************" << std::endl;
	std::cout << "classicTestMutantStack:" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;

	mstack.pop();
	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	std::cout << "********************************************************************************" << std::endl << std::endl;
}

void	TestReverseMutantStack()
{
	std::cout << "********************************************************************************" << std::endl;
	std::cout << "TestReverseMutantStack:" << std::endl;
	MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	MutantStack<int>::reverse_iterator ite = mstack.rend();
	for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != ite; ++it)
		std::cout << '[' << it - mstack.rbegin()  << "] " << *it << std::endl;
	std::cout << "********************************************************************************" << std::endl << std::endl;
}

void	classicTestList()
{
	std::cout << "********************************************************************************" << std::endl;
	std::cout << "classicTestList:" << std::endl;
	std::list<int> list;

	list.push_back(5);
	list.push_back(17);
	std::cout << list.back() << std::endl;

	list.pop_back();
	std::cout << list.size() << std::endl;
	
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::list<int> s(list);
	std::cout << "********************************************************************************" << std::endl << std::endl;
}

void	TestReverseList()
{
	std::cout << "********************************************************************************" << std::endl;
	std::cout << "TestReverseList:" << std::endl;
	std::list<int> list;

	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	std::list<int>::reverse_iterator it = list.rbegin();
	std::list<int>::reverse_iterator ite = list.rend();
	int	index = 0;
	while (it != ite)
	{
		std::cout << '[' << index << "] " << *it << std::endl;
		++it;
		++index;
	}
	std::cout << "********************************************************************************" << std::endl << std::endl;
}

int	main(void)
{
	classicTestMutantStack();
	classicTestList();
	TestReverseMutantStack();
	TestReverseList();
	return 0;
}