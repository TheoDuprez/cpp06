/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:17:41 by tduprez           #+#    #+#             */
/*   Updated: 2023/12/13 16:38:13 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
	if (this != &obj)
		*this = obj;
	return ;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
	static_cast<void>(obj);
	return *this;
}

ScalarConverter::~ScalarConverter(void)
{
	return ;
}

void	ScalarConverter::convert(const std::string& litteral)
{
	double	value;
	char	*endPtr;

	value = strtod(litteral.c_str(), &endPtr);

	if ((*endPtr != 0 && *endPtr != 'f') || litteral.length() == 0 || *(endPtr + 1) != 0 || \
	(litteral.find('.') == std::string::npos && litteral.find('f') != std::string::npos))
		std::cout << "Error: Invalid argument" << std::endl;
	else
	{
		printChar(value, litteral == "nan" || litteral == "nanf");
		printInt(value, litteral == "nan" || litteral == "nanf");
		printFloat(value);
		printDouble(value);
	}
}

void	ScalarConverter::printChar(double value, bool isnan)
{
	if (isnan == true || value < CHAR_MIN || value > CHAR_MAX)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (isprint(static_cast<char>(value)) == false)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << "'" << static_cast<char>(value) << "'" << std::endl;
}

void	ScalarConverter::printInt(double value, bool isnan)
{
	if (isnan == true || value < INT_MIN || value > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void	ScalarConverter::printFloat(double value)
{
	float	toComp = static_cast<float>(value);

	if (static_cast<int>(value) == toComp)
		std::cout << "float: " << toComp << ".0f" << std::endl;
	else
		std::cout << "float: " << toComp << "f" << std::endl;
}

void	ScalarConverter::printDouble(double value)
{
	if (static_cast<int>(value) == value)
		std::cout << "double: " << value << ".0" << std::endl;
	else
		std::cout << "double: " << value << std::endl;
}
