/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:59:58 by tduprez           #+#    #+#             */
/*   Updated: 2023/12/01 14:23:46 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter constructor" << std::endl;
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
	std::cout << "ScalarConverter copy constructor" << std::endl;
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
	std::cout << "ScalarConverter destructor" << std::endl;
	return ;
}

void	ScalarConverter::convert(const std::string& litteral)
{
	if (litteral.length() < 1)
		std::cout << "The input cannot be empty !" << std::endl;
	else if (litteral == "nan" || litteral == "nanf")
		printSpecialCase("nanf", "nan");
	else if (litteral == "inf" || litteral == "inff" || litteral == "+inf" || litteral == "+inff")
		printSpecialCase("inff", "inf");
	else if (litteral == "-inf" || litteral == "-inff")
		printSpecialCase("-inff", "-inf");
	else if (isInt(litteral) == true)
		printInt(litteral);
	else if (isFloat(litteral) == true)
		printFloat(litteral);
	else if (isDouble(litteral) == true)
		printDouble(litteral);
	else if (isChar(litteral) == true)
		printChar(litteral);
	else
		std::cout << "Error: string format" << std::endl;
	return ;
}

bool	ScalarConverter::isChar(const std::string& litteral)
{
	if (litteral.length() == 1 && isprint(static_cast<int>(litteral[0])))
		return true;
	return false;
}

bool	ScalarConverter::isInt(const std::string& litteral)
{
	for (size_t i = 0; i < litteral.length(); i++)
		if (!isdigit(litteral[i]))
			return false;
	return true;
}

bool	ScalarConverter::isFloat(const std::string& litteral)
{
	size_t	i = 0;
	int	countDot = 0;
	
	if (litteral[0] == '-')
		i++;
	if (litteral[litteral.length() - 1] != 'f')
		return false;
	for (i = 0; i < litteral.length() - 1; i++)
	{
		if (!isdigit(litteral[i]) && litteral[i] != '.')
			return false;
		else if (litteral[i] == '.')
			countDot++;
	}
	if (countDot != 1)
		return false;
	return true;
}

bool	ScalarConverter::isDouble(const std::string& litteral)
{
	size_t	i = 0;
	int	countDot = 0;
	
	if (litteral[0] == '-')
		i++;
	for (i = 0; i < litteral.length(); i++)
	{
		if (!isdigit(litteral[i]) && litteral[i] != '.')
			return false;
		else if (litteral[i] == '.')
			countDot++;
	}
	if (countDot != 1)
		return false;
	return true;
}

void	ScalarConverter::printChar(const std::string& litteral)
{
	char	c = litteral.c_str()[0];

	std::cout << "char: '"   << c << "'" << std::endl;
	std::cout << "int: "    << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
	return ;
}

void	ScalarConverter::printInt(const std::string& litteral)
{
	long long	value = atoll(litteral.c_str());

	if (value < 255 && isprint(value))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	if (value <= INT_MAX && value >= INT_MIN)
		std::cout << "int: " << value << std::endl;
	else
		std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " <<  std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
	return ;
}

void	ScalarConverter::printFloat(const std::string& litteral)
{
	float	value = atof(litteral.c_str());

	if (value < 255 && isprint(static_cast<int>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	if (static_cast<int>(value) <= INT_MAX && static_cast<int>(value) >= INT_MIN)
		std::cout << "int: " << value << std::endl;
	else
		std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
	return ;
}

void	ScalarConverter::printDouble(const std::string& litteral)
{
	double	value = atof(litteral.c_str());

	if (value < 255 && isprint(static_cast<char>(value)))
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	if (static_cast<int>(value) <= INT_MAX && static_cast<int>(value) >= INT_MIN)
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	else
		std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(value) << std::endl;
	return ;
}

void	ScalarConverter::printSpecialCase(const std::string& forFloat, const std::string& forDouble)
{
	std::cout << "char: "   << "impossible" << std::endl;
	std::cout << "int: "    << "impossible" << std::endl;
	std::cout << "float: "  << forFloat << std::endl;
	std::cout << "double: " << forDouble << std::endl;
	return ;
}

