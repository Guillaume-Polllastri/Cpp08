/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 10:15:35 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/26 15:23:12 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <iostream>

/* ************************************************************************** */

// Canonical Form

Span::Span(unsigned int N): _N(N) {}

Span::Span(const Span& copy): _container(copy._container), _N(copy._N) {}

Span&	Span::operator=(const Span& other) {
	if (this != &other)
	{
		_container = other._container;
		_N = other._N;
	}
	return *this;
}

Span::~Span() {}

/* ************************************************************************** */

// Methods

void	Span::addNumber(int value) {
	if (_container.size() >= _N)
		throw ContainerIsFull();
	_container.push_back(value);
}

int	Span::shortestSpan() {
	if (_container.size() <= 1)
		throw ContainerIsNotFullEnough();

	std::vector<int>	copy = _container;
	std::sort(copy.begin(), copy.end());
	
	std::vector<int>::iterator	it;
	int	result = copy[1] - copy[0];
	for (it = copy.begin(); (it + 1) != copy.end(); it++)
	{
		if ((*(it + 1) - *it) < result)
		{
			result = *(it + 1) - *it;
		}
	}
	return (result);
}

int	Span::longestSpan() {
	if (_container.size() <= 1)
		throw ContainerIsNotFullEnough();
	return (*std::max_element(_container.begin(), _container.end()) - *std::min_element(_container.begin(), _container.end()));
}

void	Span::printContainer() {
	std::vector<int>::iterator	it;

	for (it = _container.begin(); it != _container.end(); it++)
		std::cout << '[' << it - _container.begin() << "] " << *it << std::endl;
}
