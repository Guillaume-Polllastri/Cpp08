/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:07:45 by gpollast          #+#    #+#             */
/*   Updated: 2026/02/26 19:06:14 by gpollast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <deque>

template< typename T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack() {};
		MutantStack(const MutantStack& copy): std::stack<T>(copy) {};
		MutantStack& operator=(const MutantStack& other) {
			if (this != &other)
				std::stack<T>::operator=(other);
			return *this;
		};
		~MutantStack() {};

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
		
		const_iterator begin() const { return this->c.begin(); }
		const_iterator end() const { return this->c.end(); }
		
		reverse_iterator rbegin() { return this->c.rbegin(); }
		reverse_iterator rend() { return this->c.rend(); }
		
		const_reverse_iterator rbegin() const { return this->c.rbegin(); }
		const_reverse_iterator rend() const { return this->c.rend(); }
};
