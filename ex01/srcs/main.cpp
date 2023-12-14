/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:46:20 by tduprez           #+#    #+#             */
/*   Updated: 2023/12/14 16:34:38 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

int	main(void)
{
	uintptr_t	test;
	Data*		data = new Data(42, 420.0f, 4200.0, "42000");

	std::cout << "----------------------------------------" << std::endl;
	data->printData();
	test = Serializer::serialize(data);
	data = Serializer::deserialize(test);
	std::cout << "----------------------------------------" << std::endl;
	data->printData();
	std::cout << "----------------------------------------" << std::endl;
	reinterpret_cast<Data*>(test)->printData();
	std::cout << "----------------------------------------" << std::endl;
	if (Serializer::deserialize(Serializer::serialize(data)) == data)
		std::cout << "Same pointer" << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	delete data;
	return (0);
}
