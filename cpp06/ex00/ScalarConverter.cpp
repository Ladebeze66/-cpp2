/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:33:13 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/25 20:00:34 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << GREEN << "ScalarConverter default constructor called!" << RESET << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter&)
{
	std::cout << CYAN << "Copy constructor called for ScalarConverter." << RESET << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << RED << "ScalarConverter is destroyed!" << RESET << std::endl;
}

char ScalarConverter::convertToChar(double num)
{
	if (num < CHAR_MIN || num > CHAR_MAX || std::isnan(num) || std::isinf(num))
		throw std::runtime_error("impossible");
	else if (!std::isprint(static_cast<char>(num)))
		throw std::runtime_error("Non displayable");
	return (static_cast<char>(num));
}

int ScalarConverter::convertToInt(double num)
{
	if (num < INT_MIN || num > INT_MAX || std::isnan(num) || std::isinf(num))
		throw std::runtime_error("impossible");
	return (static_cast<int>(num));
}

float ScalarConverter::convertToFloat(double num)
{
	return (static_cast<float>(num));
}

double ScalarConverter::convertToDouble(const std::string& literal)
{
	return (std::strtod(literal.c_str(), NULL));
}

void ScalarConverter::convert(const std::string& literal)
{
	double num = convertToDouble(literal);
	try
	{
		char c = convertToChar(num);
		printAsChar(c);
	}
	catch (const std::exception& e)
	{
		std::cout << "char: " << e.what() << std::endl;
	}

	try
	{
		int i = convertToInt(num);
		printAsInt(i);
	}
	catch (const std::exception& e)
	{
		std::cout << "int: " << e.what() << std::endl;
	}

	float f = convertToFloat(num);
	printAsFloat(f);

	printAsDouble(num);
}

void ScalarConverter::printAsChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::printAsInt(int i)
{
	std::cout << "int: " << i << std::endl;
}

void ScalarConverter::printAsFloat(float f)
{
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << 'f' << std::endl;
}

void ScalarConverter::printAsDouble(double d)
{
	std::cout << std::fixed << std::setprecision(1) << "double: " << d << std::endl;
}