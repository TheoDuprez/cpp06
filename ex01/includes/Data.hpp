/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:19:06 by tduprez           #+#    #+#             */
/*   Updated: 2023/12/14 16:50:29 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

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

#endif
