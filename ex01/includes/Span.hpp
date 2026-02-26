/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 10:15:26 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/26 15:32:52 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <exception>

class Span {
	private:
		std::vector<int>	_container;
		unsigned int 		_N;
	
	public:
		Span(unsigned int N);
		Span(const Span& copy);
		Span&	operator=(const Span& other);
		~Span();

		void	addNumber(int value);
		template< typename RangeIterator>
		void	addNumber(RangeIterator begin, RangeIterator end) {
			for (RangeIterator it = begin; it != end; it++)
				_container.push_back(*it);
		}
		int		shortestSpan();
		int		longestSpan();
		void	printContainer();

		class ContainerIsFull: public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return "The container is full !";
				}
		};

		class ContainerIsNotFullEnough: public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return "The container is not full enough !";
				}
		};
};