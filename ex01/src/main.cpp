/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 08:15:08 by akyoshid          #+#    #+#             */
/*   Updated: 2025/07/09 14:50:59 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <limits>
#include "../inc/PhoneBook.hpp"
#include "../inc/utils.hpp"
#include "../inc/colors.hpp"

int	print_misuse(){
	std::cerr
		<< RED << "phonebook: extra operand or invalid option"
		<< RESET << std::endl
		<< "Usage: phonebook" << std::endl;
	return 2;
}

void	reader_loop(){
	PhoneBook	phonebook;
	std::string	input;

	while (1){
		std::cout << MAGENTA << "phonebook> " << RESET;
		w_getline(input);
		if (input.empty())
			continue ;
		else if (input.compare("ADD") == 0)
			phonebook.add_contact();
		else if (input.compare("SEARCH") == 0)
			phonebook.search_contact();
		else if (input.compare("EXIT") == 0){
			std::cout << GREEN << "Exit" << RESET << std::endl;
			return ;
		}
		else
			std::cout << RED << "Invalid command..." << RESET << std::endl;
	}
}

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc != 1)
		return print_misuse();
	reader_loop();
	return 0;
}
