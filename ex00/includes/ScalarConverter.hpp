/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:46:37 by tduprez           #+#    #+#             */
/*   Updated: 2023/12/01 12:59:33 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <climits>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& obj);
	ScalarConverter& operator=(const ScalarConverter& obj);
	~ScalarConverter(void);



	static bool	isChar(const std::string& litteral);
	static bool	isInt(const std::string& litteral);
	static bool	isFloat(const std::string& litteral);
	static bool	isDouble(const std::string& litteral);

	static void	printChar(const std::string& litteral);
	static void	printInt(const std::string& litteral);
	static void	printFloat(const std::string& litteral);
	static void	printDouble(const std::string& litteral);
	static void	printSpecialCase(const std::string& forFloat, const std::string& forDouble);

public:
	static void	convert(const std::string& litteral);

};
