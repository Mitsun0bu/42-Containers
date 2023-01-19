/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:01:41 by llethuil          #+#    #+#             */
/*   Updated: 2023/01/16 14:12:59 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iostream>
#include "iterator.hpp"

namespace ft
{
	template <typename vector>
	class Reverse_iterator : public Iterator<vector>
	{
		public:

			Reverse_iterator() : Iterator<vector>()
			{
				return ;
			}

			Reverse_iterator(typename vector::pointer ptr)
				: Iterator<vector>(ptr)
			{
				return ;
			}

			Reverse_iterator& operator++()
			{
				--this->_ptr;
				return (*this);
			}

			Reverse_iterator operator++(int)
			{
				Reverse_iterator it = *this;
				--(*this);
				return (it);
			}

			Reverse_iterator& operator--()
			{
				++this->_ptr;
				return (*this);
			}

			Reverse_iterator operator--(int)
			{
				Reverse_iterator iterator = *this;
				++(*this);
				return (iterator);
			}
	};
}

#endif