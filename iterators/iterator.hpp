/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:48:45 by llethuil          #+#    #+#             */
/*   Updated: 2023/01/16 14:20:27 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>

namespace ft
{
	template < typename vector >
	class Iterator
	{
		public:

			// TYPE DEFINITIONS
			typedef typename vector::value_type		value_type;
			typedef ptrdiff_t						difference_type;
			typedef std::random_access_iterator_tag	iterator_category;
			typedef value_type*						pointer;
			typedef value_type&						reference;

			// DEFAULT CONSTRUCTOR
			Iterator()
				: _ptr(NULL)
			{
				return ;
			}

			// CONSTRUCTOR
			Iterator(pointer ptr)
				: _ptr(ptr)
			{
				return ;
			}

			// PREFIX INCREMENT OPERATOR
			Iterator& operator++()
			{
				_ptr++;
				return (*this);
			}

			// POSTFIX INCREMENT OPERATOR
			Iterator operator++(int)
			{
				Iterator  it = *this;
				++(*this);
				return (it);
			}

			// PREFIX DECREMENT OPERATOR
			Iterator& operator--()
			{
				_ptr--;
				return (*this);
			}

			// POSTFIX DECREMENT OPERATOR
			Iterator operator--(int)
			{
				Iterator  it = *this;
				--(*this);
				return (it);
			}

			// ARITHMETIC OPERATOR '+' ON INT
			Iterator operator+(int n)
			{
				Iterator it = *this;
				it += n;
				return (it);
			}

			// ARITHMETIC OPERATOR '-' ON INT
			Iterator operator-(int n)
			{
				Iterator it = *this;
				it -= n;
				return (it);
			}

			// ARITHMETIC OPERATOR '-' ON ANOTHER VECTOR
			difference_type operator-(const Iterator& other) const
			{
				return (_ptr - other._ptr);
			}

			// POSTFIX INCREMENT OPERATOR
			Iterator& operator+=(int n)
			{
				_ptr += n;
				return (*this);
			}

			// PREFIX DECREMENT OPERATOR
			Iterator& operator-=(int n)
			{
				_ptr -= n;
				return (*this);
			}

			reference	operator[](int n)
			{
				return *(_ptr + n);
			}

			reference	operator->()
			{
				return (_ptr);
			}

			reference	operator*()
			{
				return (*_ptr);
			}

			bool	operator==(const Iterator& x) const
			{
				if (_ptr == x._ptr)
					return (true);
				return (false);
			}

			bool	operator!=(const Iterator& x) const
			{
				if (_ptr != x._ptr)
					return (true);
				return (false);
			}

			bool	operator<(const Iterator& x) const
			{
				return (_ptr < x._ptr);
			}

			bool	operator>(const Iterator& x) const
			{
				return (_ptr > x._ptr);
			}

			bool	operator<=(const Iterator& x) const
			{
				return (_ptr <= x._ptr);
			}

			bool	operator>=(const Iterator& x) const
			{
				return (_ptr >= x._ptr);
			}

		protected:

			pointer _ptr;
	};
}

#endif