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
	class Reverse_iterator
	{
		public:

			/* ********************************** */
            /*                                    */
            /*      ~~~ TYPE DEFINITIONS ~~~      */
            /*                                    */
            /* ********************************** */

			typedef typename	vector::value_type	value_type;
			typedef 			value_type*			pointer;
			typedef				value_type&			reference;

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