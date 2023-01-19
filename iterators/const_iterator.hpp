/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Const_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:01:05 by llethuil          #+#    #+#             */
/*   Updated: 2023/01/16 14:14:14 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_ITERATOR_HPP
#define CONST_ITERATOR_HPP

#include <iostream>
#include "iterator.hpp"

namespace ft
{
	template <typename vector>
	class Const_iterator : public Iterator<vector>
	{
		public:

			Const_iterator() : Iterator<vector>()
			{
				return ;
			}

			Const_iterator(typename vector::pointer ptr)
				: Iterator<vector>(ptr)
			{
				return ;
			}

			Const_iterator& operator++()
			{
				++this->_ptr;
				return (*this);
			}

			Const_iterator operator++(int)
			{
				Const_iterator	it = *this;
				++(*this);
				return (it);
			}

			Const_iterator& operator--()
			{
				--this->_ptr;
				return *this;
			}

			Const_iterator operator--(int)
			{
				Const_iterator it = *this;
				--(*this);
				return (it);
			}

			const typename vector::value_type& operator*() const
			{
				return *(this->_ptr);
			}

			const typename vector::value_type* operator->() const
			{
				return (this->_ptr);
			}
	};
}

#endif