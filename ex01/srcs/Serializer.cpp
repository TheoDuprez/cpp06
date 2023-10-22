/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:47:11 by tduprez           #+#    #+#             */
/*   Updated: 2023/10/22 13:35:01 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Serializer constructor" << std::endl;
	return ;
}

Serializer::Serializer(const Serializer& obj)
{
	std::cout << "Serializer copy constructor" << std::endl;
	*this = obj;
	return ;
}

Serializer& Serializer::operator=(const Serializer& obj)
{
	static_cast<void>(obj);
	return *this;
}

Serializer::~Serializer(void)
{
	std::cout << "Serializer destructor" << std::endl;
	return ;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t	res;

	res = reinterpret_cast<uintptr_t>(ptr);
	return res;
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	Data*	ptr;

	ptr = reinterpret_cast<Data*>(raw);
	return ptr;
}


