/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:53:39 by akyoshid          #+#    #+#             */
/*   Updated: 2025/06/29 17:28:19 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

int	main(int argc, char *argv[]){
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else{
		for (int i = 1; i < argc; i++){
			std::string	str(argv[i]);
			for (size_t j = 0; j < str.length(); j++)
				std::cout << (char)std::toupper(str[j]);
		}
	}
	std::cout << std::endl;
	if (std::cout.fail() == true){
		std::cerr << "megaphone: Failed to write to standard output";
		std::cerr << std::endl;
		return (1);
	}
	return (0);
}
