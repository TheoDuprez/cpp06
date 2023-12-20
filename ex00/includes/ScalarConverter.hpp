/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:46:37 by tduprez           #+#    #+#             */
/*   Updated: 2023/12/20 10:45:30 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <limits>

#define CHAR 0
#define INT 1
#define FLOAT 2
#define DOUBLE 3

class ScalarConverter
{
private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& obj);
	ScalarConverter& operator=(const ScalarConverter& obj);
	~ScalarConverter(void);

	static bool	isGoodFormat(const std::string& str);
	static bool	isInf(const std::string& str);
	static int	getRealType(const std::string& str);
	static void	setChar(const std::string& str, char& c, int& i, float& f, double& d);
	static void	setInt(const std::string& str, char& c, int& i, float& f, double& d);
	static void	setFloat(const std::string& str, char& c, int& i, float& f, double& d);
	static void	setDouble(const std::string& str, char& c, int& i, float& f, double& d);
	static void	print(std::string str, char c, int i, float f, double d);

public:
	static void	convert(const std::string& litteral);

};

#endif
