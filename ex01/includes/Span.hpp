/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 10:15:26 by gpollast          #+#    #+#             */
/*   Updated: 2026/03/18 17:29:59 by gpollast         ###   ########.fr       */
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
			if ((std::distance(begin, end) + _container.size()) > _N)
				throw ContainerIsFull();
			_container.insert(_container.end(), begin, end);
		}
		
		unsigned int		shortestSpan();
		unsigned int		longestSpan();
		void				printContainer();

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