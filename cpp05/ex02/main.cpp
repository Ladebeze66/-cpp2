/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgras-ca <fgras-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:55:46 by fgras-ca          #+#    #+#             */
/*   Updated: 2024/02/25 13:18:30 by fgras-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <exception>

int main()
{
	std::cout << CYAN << "\n--- Creation ---\n\n" << RESET;
	// Création des bureaucrates
	Bureaucrat john("John", 2);
	Bureaucrat doe("Doe", 150);

	// Création des formulaires
	ShrubberyCreationForm shrub("Home");
	RobotomyRequestForm robot("Robot");
	PresidentialPardonForm pardon("Criminal");

	// Tentatives de signature et d'exécution des formulaires par John
	std::cout << CYAN << "\n--- John tries to sign and execute forms ---\n\n" << RESET;

	john.signForm(shrub);
	john.executeForm(shrub);

	john.signForm(robot);
	john.executeForm(robot);

	john.signForm(pardon);
	john.executeForm(pardon);

	// Tentatives de signature et d'exécution des formulaires par Doe
	std::cout << CYAN << "\n--- Doe tries to sign and execute forms ---\n\n" << RESET;

	doe.signForm(shrub);
	doe.executeForm(shrub);
	doe.executeForm(robot);

	// Tentatives de signature et d'exécution des formulaires avec gestion des exceptions
	std::cout << CYAN << "\n--- Additional tests with exception handling ---\n\n" << RESET;

	doe.signForm(robot);
	doe.executeForm(robot);
	doe.signForm(pardon);
	doe.executeForm(pardon);

	// Test avec un formulaire déjà signé
	std::cout << CYAN << "\n--- Testing with already signed form ---\n\n" << RESET;

	john.signForm(shrub); // shrub est déjà signé par John plus tôt
	john.executeForm(shrub);

	return (0);
}
