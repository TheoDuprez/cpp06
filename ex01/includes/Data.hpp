/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:19:06 by tduprez           #+#    #+#             */
/*   Updated: 2023/10/22 13:43:21 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Data
{
private:
	int			_intValue;
	float		_floatValue;
	double		_doubleValue;
	std::string	_stringValue;

public:
	Data(void);
	Data(int intValue, float floatValue, double doubleValue, std::string stringValue);
	Data(const Data& obj);
	Data&	operator=(const Data& obj);
	~Data(void);

void	printData(void) const;

};
