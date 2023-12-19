/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:17:41 by tduprez           #+#    #+#             */
/*   Updated: 2023/12/19 13:58:34 by tduprez          ###   ########lyon.fr   */
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

void ScalarConverter::convert(const std::string& litteral)
{
	char	c;
	int		i;
	float	f;
	double	d;
	int	real_type = getRealType(litteral);
	
	switch(real_type)
	{
		case CHAR:
			setChar(litteral, c, i, f, d);
			break;
		case INT:
			setInt(litteral, c, i, f, d);
			break;
		case FLOAT:
			setFloat(litteral, c, i, f, d);
			break;
		case DOUBLE:
			setDouble(litteral, c, i, f, d);
			break;
		default:
			std::cout << "Error: bad string format" << std::endl;
			return ;
	}
	print(litteral, c, i, f, d);
}

int ScalarConverter::getRealType(const std::string& str)
{
	int		i;
	float	f;
	double	d;

	std::istringstream	iss(str);
	std::istringstream	fss(str.substr(0, str.length() - 1));
	std::istringstream	dss(str);

	if (str == "nanf" || str == "+inff" || str == "-inff")
		return (FLOAT);
	else if (str == "nan" || str == "+inf" || str == "-inf")
		return (DOUBLE);

	iss >> i;
	dss >> d;
	fss >> f;

	if (str.length() == 1 && !isdigit(str[0]))
		return CHAR;
	else if (iss.eof() && !iss.fail())
		return INT;
	else if (dss.eof() && !dss.fail())
		return DOUBLE;
	else if (fss.eof() && !fss.fail())
		return FLOAT;

	return -1;
}

void	ScalarConverter::setChar(const std::string& str, char& c, int& i, float& f, double& d)
{
	c = str[0];
	i = static_cast<int>(c);
	f = static_cast<float>(c);
	d = static_cast<double>(c);

	return ;
}

void	ScalarConverter::setInt(const std::string& str, char& c, int& i, float& f, double& d)
{
	i = std::atoi(str.c_str());
	c = static_cast<char>(i);
	f = static_cast<float>(i);
	d = static_cast<double>(i);

	std::cout << static_cast<int>(c) << std::endl;

	return ;
}

void	ScalarConverter::setFloat(const std::string& str, char& c, int& i, float& f, double& d)
{
	f = std::strtof(str.c_str(), NULL);
	c = static_cast<char>(f);
	i = static_cast<int>(f);
	d = static_cast<double>(f);

	return ;
}

void	ScalarConverter::setDouble(const std::string& str, char& c, int& i, float& f, double& d)
{
	d = std::strtod(str.c_str(), NULL);
	c = static_cast<char>(d);
	i = static_cast<int>(d);
	f = static_cast<float>(d);

	return ;
}

void	ScalarConverter::print(std::string str, char c, int i, float f, double d)
{
	bool	isnan = str == "nan" || str == "nanf";

	{
		std::cout << "char: ";
		if (isnan == true)
			std::cout << "impossible" << std::endl;
		else if (i < 0 || i > 127 || !std::isprint(i))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << c << "'" << std::endl;
	}
	{
		if (isnan == true || d > static_cast<double>(std::numeric_limits<int>::max()) || d < static_cast<double>(std::numeric_limits<int>::min()))
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << i << std::endl;
	}
	{
		std::cout << "float: ";
		if (isnan == true)
			std::cout << "nanf" << std::endl;
		else if (f - static_cast<int>(f) == 0)
			std::cout << f << ".0f" << std::endl;
		else
			std::cout << f << "f" << std::endl;
	}
	{
		std::cout << "double: ";
		if (isnan == true)
			std::cout << "nan" << std::endl;
		else if (d - static_cast<int>(d) == 0)
			std::cout << d << ".0" << std::endl;
		else
			std::cout << d << std::endl;
	}
	return ;
}
