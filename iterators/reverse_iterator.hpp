/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:01:41 by llethuil          #+#    #+#             */
/*   Updated: 2023/01/19 14:32:42 by llethuil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iostream>
#include "iterator.hpp"

namespace ft
{
	template <typename vector>
	class Reverse_iterator
	{
		public:

			/* ********************************** */
            /*                                    */
            /*      ~~~ TYPE DEFINITIONS ~~~      */
            /*                                    */
            /* ********************************** */

			typedef typename	vector::value_type				value_type;
			typedef				ptrdiff_t						difference_type;
			typedef 			std::random_access_iterator_tag	iterator_category;
			typedef 			value_type*						pointer;
			typedef				value_type&						reference;

			/* ************************************* */
            /*                                       */
            /*      ~~~ DEFAULT CONSTRUCTOR ~~~      */
            /*                                       */
            /* ************************************* */

			Reverse_iterator() : _ptr()
			{
				return ;
			}

			/* ***************************** */
            /*                               */
            /*      ~~~ CONSTRUCTOR ~~~      */
            /*                               */
            /* ***************************** */

			Reverse_iterator(pointer ptr)
				: _ptr(ptr)
			{
				return ;
			}

			/* ********************************** */
            /*                                    */
            /*      ~~~ COPY CONSTRUCTOR ~~~      */
            /*                                    */
            /* ********************************** */

			Reverse_iterator(const Reverse_iterator& src)
				: _ptr(src._ptr)
			{
				return ;
			}

			/* **************************** */
            /*                              */
            /*      ~~~ DESTRUCTOR ~~~      */
            /*                              */
            /* **************************** */

			~Reverse_iterator()
			{
				return ;
			}

			/* ******************************************* */
            /*                                             */
            /*      ~~~ PREFIX INCREMENT OPERATOR ~~~      */
            /*                                             */
            /* ******************************************* */

			Reverse_iterator& operator++()
			{
				--this->_ptr;
				return (*this);
			}

			/* ******************************************** */
			/*                                              */
			/*      ~~~ POSTFIX INCREMENT OPERATOR ~~~      */
			/*                                              */
			/* ******************************************** */

			Reverse_iterator operator++(int)
			{
				Reverse_iterator it = *this;
				--(*this);
				return (it);
			}

			/* ******************************************* */
			/*                                             */
			/*      ~~~ PREFIX DECREMENT OPERATOR ~~~      */
			/*                                             */
			/* ******************************************* */

			Reverse_iterator& operator--()
			{
				++this->_ptr;
				return (*this);
			}

			/* ******************************************** */
			/*                                              */
			/*      ~~~ POSTFIX DECREMENT OPERATOR ~~~      */
			/*                                              */
			/* ******************************************** */

			Reverse_iterator operator--(int)
			{
				Reverse_iterator iterator = *this;
				++(*this);
				return (iterator);
			}

			/* ************************************** */
			/*                                        */
			/*      ~~~ ARITHMETIC OPERATORS ~~~      */
			/*                                        */
			/* ************************************** */

			// OPERATOR '+' ON INT
			// Reverse_iterator operator+(int n)
			// {
			// 	Reverse_iterator it = *this;
			// 	it += n;
			// 	return (it);
			// }

			Reverse_iterator operator+(difference_type n) const
			{
				Reverse_iterator it = *this;
				it += n;
				return (it);
			}

			// OPERATOR '-' ON INT
			// Reverse_iterator operator-(int n)
			// {
			// 	Reverse_iterator it = *this;
			// 	it -= n;
			// 	return (it);
			// }

			Reverse_iterator operator-(difference_type n) const
			{
				Reverse_iterator it = *this;
				it -= n;
				return (it);
			}

			// OPERATOR '-' ON ANOTHER VECTOR
			difference_type operator-(const Reverse_iterator& other) const
			{
				return (_ptr - other._ptr);
			}

			/* ************************************* */
            /*                                       */
            /*      ~~~ ASSIGNMENT OPERATOR ~~~      */
            /*                                       */
            /* ************************************* */

			Reverse_iterator& operator=(const Reverse_iterator& src)
			{
				if (this != &src)
					_ptr = src._ptr;

				return (*this);
			}
	
			Reverse_iterator& operator+=(difference_type n)
			{
				_ptr += n;
				return (*this);
			}

			Reverse_iterator& operator-=(difference_type n)
			{
				_ptr -= n;
				return (*this);
			}
		
			/* *************************************** */
			/*                                         */
			/*      ~~~ DEREFERENCE OPERATORS ~~~      */
			/*                                         */
			/* *************************************** */

			reference operator*() const
			{
				return (*_ptr);
			}

			reference operator->() const
			{
				return (_ptr);
			}

			/* ********************************************** */
			/*                                                */
			/*      ~~~ OFFSET DEREFERENCE OPERATORS ~~~      */
			/*                                                */
			/* ********************************************** */

			reference	operator[](int n)
			{
				return *(_ptr - n - 1);
			}
		
			/* *********************************************** */
			/*                                                 */
			/*      ~~~ EQUALITY/INEQUALITY OPERATORS ~~~      */
			/*                                                 */
			/* *********************************************** */

			bool	operator==(const Reverse_iterator& x) const
			{
				if (_ptr == x._ptr)
					return (true);
				return (false);
			}

			bool	operator!=(const Reverse_iterator& x) const
			{
				if (_ptr != x._ptr)
					return (true);
				return (false);
			}

			bool	operator<(const Reverse_iterator& x) const
			{
				return (_ptr < x._ptr);
			}

			bool	operator>(const Reverse_iterator& x) const
			{
				return (_ptr > x._ptr);
			}

			bool	operator<=(const Reverse_iterator& x) const
			{
				return (_ptr <= x._ptr);
			}

			bool	operator>=(const Reverse_iterator& x) const
			{
				return (_ptr >= x._ptr);
			}

		private :

			pointer _ptr;
	};
}

#endif