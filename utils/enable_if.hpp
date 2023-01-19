/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:41:30 by llethuil          #+#    #+#             */
/*   Updated: 2023/01/16 13:49:20 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

namespace ft
{
	template <bool B, class T = void>
	struct enable_if
	{

	};

	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
}

#endif