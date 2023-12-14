/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:46:37 by tduprez           #+#    #+#             */
/*   Updated: 2023/12/14 15:38:32 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>

#define MAX_PRINTABLE 999999

class ScalarConverter
{
private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& obj);
	ScalarConverter& operator=(const ScalarConverter& obj);
	~ScalarConverter(void);

	static void	printChar(double value, bool isnan);
	static void	printInt(double value, bool isnan);
	static void	printFloat(double value);
	static void	printDouble(double value);

public:
	static void	convert(const std::string& litteral);

};
