/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 18:32:55 by akyoshid          #+#    #+#             */
/*   Updated: 2025/07/09 14:46:14 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.hpp"

void	w_getline(std::string &input){
	std::getline(std::cin, input);
	if (std::cin.eof()){
		std::cerr << "^D\n" << GREEN << "Exit" << RESET << std::endl;
		std::exit(0);
	}
	else if (std::cin.bad()){
		std::cerr << RED << "Fatal error\nExit" << RESET << std::endl;
		std::exit(1);
	}
	else if (std::cin.fail()){
		std::cerr << RED << "Error\nExit" << RESET << std::endl;
		std::exit(1);
	}
}
