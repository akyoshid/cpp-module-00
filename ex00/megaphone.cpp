/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 15:53:39 by akyoshid          #+#    #+#             */
/*   Updated: 2025/06/29 18:53:22 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

std::string	str_to_upper(std::string str){
	for (size_t i = 0; i < str.length(); ++i){
		str[i] = (char)std::toupper(str[i]);
	}
	return str;
}

int	main(int argc, char *argv[]){
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else{
		for (int i = 1; i < argc; i++)
			std::cout << str_to_upper(argv[i]);
	}
	std::cout << std::endl;
	if (std::cout.fail() == true){
		std::cerr << "megaphone: Failed to write to standard output";
		std::cerr << std::endl;
		return 1;
	}
	return 0;
}
