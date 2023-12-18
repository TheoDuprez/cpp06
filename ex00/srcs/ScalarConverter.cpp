/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:17:41 by tduprez           #+#    #+#             */
/*   Updated: 2023/12/18 14:08:52 by tduprez          ###   ########lyon.fr   */
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

void	ScalarConverter::setChar(const std::string& str, char c, int i, float f, double d)
{
}
