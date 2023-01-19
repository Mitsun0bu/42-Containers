/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <lucas.lethuillier@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:48:45 by llethuil          #+#    #+#             */
/*   Updated: 2023/01/19 16:30:41 by llethuil         ###   ########.fr       */
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

			/* ********************************** */
            /*                                    */
            /*      ~~~ TYPE DEFINITIONS ~~~      */
            /*                                    */
            /* ********************************** */

			typedef typename vector::value_type		value_type;
			typedef ptrdiff_t						difference_type;
			typedef std::random_access_iterator_tag	iterator_category;
			typedef value_type*						pointer;
			typedef value_type&						reference;

			/* ************************************* */
            /*                                       */
            /*      ~~~ DEFAULT CONSTRUCTOR ~~~      */
            /*                                       */
            /* ************************************* */

			Iterator()
				: _ptr(NULL)
			{
				return ;
			}

			/* ***************************** */
            /*                               */
            /*      ~~~ CONSTRUCTOR ~~~      */
            /*                               */
            /* ***************************** */

			Iterator(pointer ptr)
				: _ptr(ptr)
			{
				return ;
			}

			/* ********************************** */
            /*                                    */
            /*      ~~~ COPY CONSTRUCTOR ~~~      */
            /*                                    */
            /* ********************************** */

			Iterator(const Iterator& src)
				: _ptr(src._ptr)
			{
				return ;
			}

			/* **************************** */
            /*                              */
            /*      ~~~ DESTRUCTOR ~~~      */
            /*                              */
            /* **************************** */

			~Iterator()
			{
				return ;
			}

			/* ******************************************* */
            /*                                             */
            /*      ~~~ PREFIX INCREMENT OPERATOR ~~~      */
            /*                                             */
            /* ******************************************* */

			Iterator& operator++()
			{
				_ptr++;
				return (*this);
			}

			/* ******************************************** */
			/*                                              */
			/*      ~~~ POSTFIX INCREMENT OPERATOR ~~~      */
			/*                                              */
			/* ******************************************** */

			Iterator operator++(int)
			{
				Iterator  it = *this;
				++(*this);
				return (it);
			}

			/* ******************************************* */
			/*                                             */
			/*      ~~~ PREFIX DECREMENT OPERATOR ~~~      */
			/*                                             */
			/* ******************************************* */

			Iterator& operator--()
			{
				_ptr--;
				return (*this);
			}

			/* ******************************************** */
			/*                                              */
			/*      ~~~ POSTFIX DECREMENT OPERATOR ~~~      */
			/*                                              */
			/* ******************************************** */

			Iterator operator--(int)
			{
				Iterator  it = *this;
				--(*this);
				return (it);
			}

			/* ************************************** */
			/*                                        */
			/*      ~~~ ARITHMETIC OPERATORS ~~~      */
			/*                                        */
			/* ************************************** */

			// OPERATOR '+' ON n
			Iterator operator+(difference_type n) const
			{
				Iterator it = *this;
				it += n;
				return (it);
			}

			// OPERATOR '-' ON n
			Iterator operator-(difference_type n) const
			{
				Iterator it = *this;
				it -= n;
				return (it);
			}

			// OPERATOR '-' ON ANOTHER VECTOR
			difference_type operator-(const Iterator& other) const
			{
				return (_ptr - other._ptr);
			}

			/* ************************************** */
			/*                                        */
			/*      ~~~ ASSIGNMENT OPERATORS ~~~      */
			/*                                        */
			/* ************************************** */

			Iterator& operator=(const Iterator& src)
			{
				if (this != &src)
					_ptr = src._ptr;

				return (*this);
			}

			Iterator& operator+=(int n)
			{
				_ptr += n;
				return (*this);
			}

			Iterator& operator-=(int n)
			{
				_ptr -= n;
				return (*this);
			}

			/* *************************************** */
			/*                                         */
			/*      ~~~ DEREFERENCE OPERATORS ~~~      */
			/*                                         */
			/* *************************************** */

			reference	operator*()
			{
				return (*_ptr);
			}

			reference	operator->()
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
				return *(_ptr + n);
			}

			/* *********************************************** */
			/*                                                 */
			/*      ~~~ EQUALITY/INEQUALITY OPERATORS ~~~      */
			/*                                                 */
			/* *********************************************** */

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