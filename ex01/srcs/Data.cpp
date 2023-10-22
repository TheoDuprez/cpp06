/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:19:23 by tduprez           #+#    #+#             */
/*   Updated: 2023/10/22 13:34:52 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Data.hpp"

Data::Data(void): _intValue(42), _floatValue(42.0f), _doubleValue(42.0), _stringValue("42")
{
	std::cout << "Data constructor" << std::endl;
	return ;
}

Data::Data(int intValue, float floatValue, double doubleValue, std::string stringValue): \
_intValue(intValue), _floatValue(floatValue), _doubleValue(doubleValue), _stringValue(stringValue)
{
	std::cout << "Data by value constructor" << std::endl;
	return ;
}

Data::Data(const Data& obj)
{
	std::cout << "Data copy constructor" << std::endl;
	*this = obj;
	return ;
}

Data& Data::operator=(const Data& obj)
{
	if (this != &obj)
	{
		this->_intValue = obj._intValue;
		this->_floatValue = obj._floatValue;
		this->_doubleValue = obj._doubleValue;
		this->_stringValue = obj._stringValue;
	}
	return *this;
}

Data::~Data(void)
{
	std::cout << "Data destructor" << std::endl;
	return ;
}

void	Data::printData(void) const
{
	std::cout << this->_intValue << std::endl;
	std::cout << this->_floatValue << std::endl;
	std::cout << this->_doubleValue << std::endl;
	std::cout << this->_stringValue << std::endl;
	return ;
}
