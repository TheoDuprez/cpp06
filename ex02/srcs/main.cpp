/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduprez <tduprez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:46:20 by tduprez           #+#    #+#             */
/*   Updated: 2023/12/20 11:05:17 by tduprez          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

static Base*	generate(void);
static void		identify(Base* p);
static void		identify(Base& p);

int	main(void)
{
	Base *base = generate();

	identify(base);
	identify(*base);

	delete base;
	return (0);
}

static Base*	generate(void)
{
	Base	*base = NULL;
	std::srand(std::time(0));

	switch (std::rand() % 3)
	{
		case 0:
			std::cout << "Type created is A." << std::endl;
			base = static_cast<Base*>(new A());
			break;
		case 1:
			std::cout << "Type created is B." << std::endl;
			base = static_cast<Base*>(new B());
			break;
		case 2:
			std::cout << "Type created is C." << std::endl;
			base = static_cast<Base*>(new C());
			break;
	}

	return base;
}

static void	identify(Base* p)
{
	Base*	test = NULL;

	std::cout << "Identify real type by pointer." << std::endl;
	test = dynamic_cast<A*>(p);
	if (test != NULL)
	{
		std::cout << "The real type of Base is A !" << std::endl;
		return ;
	}

	test = dynamic_cast<B*>(p);
	if (test != NULL)
	{
		std::cout << "The real type of Base is B !" << std::endl;
		return ;
	}

	test = dynamic_cast<C*>(p);
	if (test != NULL)
	{
		std::cout << "The real type of Base is C !" << std::endl;
		return ;
	}

	if (test == NULL)
		std::cout << "Error with casts !" << std::endl;
	return ;
}

static void	identify(Base& p)
{
	Base	test;

	std::cout << "Identify real type by reference." << std::endl;
	try
	{
		test = dynamic_cast<A&>(p);
		std::cout << "The real type of Base is A !" << std::endl;
		return ;
	}
	catch (...) {}
	try
	{
		test = dynamic_cast<B&>(p);
		std::cout << "The real type of Base is B !" << std::endl;
		return ;
	}
	catch (...) {}
	try
	{
		test = dynamic_cast<C&>(p);
		std::cout << "The real type of Base is C !" << std::endl;
		return ;
	}
	catch (...) {
		std::cout << "Error with casts !" << std::endl;
	}

	return ;
}
