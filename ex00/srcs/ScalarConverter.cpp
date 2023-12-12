/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:17:41 by tduprez           #+#    #+#             */
/*   Updated: 2023/12/12 14:00:16 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void	ScalarConverter::convert(const std::string& litteral)
{
	double	value;
	char	*endPtr;

	value = strtod(litteral.c_str(), &endPtr);

	std::cout << static_cast<int>(*endPtr) << std::endl;
	if ((*endPtr != 0 && *endPtr != 'f') || litteral.length() == 0 || !(litteral == "nanf" || litteral == "nan" || litteral == "inff" || litteral == "+inff" || litteral == "-inff"))
		std::cout << "string: impossible" << std::endl;
	else
	{
		printChar(value, litteral == "nan");
		printInt(value, litteral == "nan");
		printFloat(value, litteral == "nan");
		printDouble(value, litteral == "nan");
	}
}

void	ScalarConverter::printChar(double value, bool isnan)
{
	if (isnan == true || static_cast<char>(value) < CHAR_MIN || static_cast<char>(value) > CHAR_MAX)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(value) << std::endl;
}

void	ScalarConverter::printInt(double value, bool isnan)
{
	if (isnan == true || value < INT_MIN || value > INT_MAX)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void	ScalarConverter::printFloat(double value, bool isnan)
{
	
}

void	ScalarConverter::printDouble(double value, bool isnan)
{
	
}

