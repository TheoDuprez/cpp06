/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:46:37 by tduprez           #+#    #+#             */
/*   Updated: 2023/10/21 19:59:54 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>

class	Data;

class Serializer
{
private:
	Serializer(void);
	Serializer(const Serializer& obj);
	Serializer&	operator=(const Serializer& obj);
	~Serializer(void);

public:

	static	uintptr_t serialize(Data* ptr);
	static	Data* deserialize(uintptr_t raw);

};
