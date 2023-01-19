/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:45:08 by llethuil          #+#    #+#             */
/*   Updated: 2023/01/16 14:23:54 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <iostream>
# include "iterator.hpp"

namespace ft
{
	template <class iterator>
	struct iterator_traits
	{
		typedef typename iterator::value_type			value_type;
		typedef typename iterator::difference_type		difference_type;
		typedef typename iterator::iterator_category	iterator_category;
		typedef typename iterator::pointer				pointer;
		typedef typename iterator::reference			reference;
	};

	template <class T>
	struct iterator_traits<T*>
	{
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef std::random_access_iterator_tag	iterator_category;
		typedef T*								pointer;
		typedef T&								reference;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef const T							value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef std::random_access_iterator_tag	iterator_category;
		typedef const T*						pointer;
		typedef const T&						reference;
	};
}

#endif