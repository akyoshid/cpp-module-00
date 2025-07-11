/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:27:27 by akyoshid          #+#    #+#             */
/*   Updated: 2025/07/11 15:16:33 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook(){
	contact_count = 0;
	oldest_index = 0;
}

PhoneBook::~PhoneBook(){
}

bool	PhoneBook::check_available_char_set(std::string& input){
	for (size_t i = 0; i < input.length(); ++i){
		if (input[i] < ' ' || input[i] > '~'){
			std::cout << RED << "Input contains unacceptable characters. "
				"Please try again." << RESET << std::endl;
			return false;
		}
	}
	return true;
}

bool	PhoneBook::check_available_num_set(std::string& input){
	for (size_t i = 0; i < input.length(); ++i){
		if (input[i] < '0' || input[i] > '9'){
			std::cout << RED << "This field accepts numbers only (0-9). "
				"Please try again." << RESET << std::endl;
			return false;
		}
	}
	return true;
}

bool PhoneBook::check_blank(std::string& input){
	for (size_t i = 0; i < input.length(); ++i){
		if (input[i] != ' ')
			return false;
	}
	return true;
}

void	PhoneBook::get_valid_input_char(
			std::string prompt, std::string& input){
	while (1){
		std::cout << CYAN << prompt << RESET;
		w_getline(input);
		if (input.empty() || check_blank(input)){
			std::cout << RED << "This field is required." << RESET << std::endl;
			continue ;
		}else if (!check_available_char_set(input))
			continue ;
		else
			break ;
	}
}

void	PhoneBook::get_valid_input_num(
			std::string prompt, std::string& input){
	while (1){
		std::cout << CYAN << prompt << RESET;
		w_getline(input);
		if (input.empty() || check_blank(input)){
			std::cout << RED << "This field is required." << RESET << std::endl;
			continue ;
		}else if (!check_available_num_set(input))
			continue ;
		else
			break;
	}
}

bool	PhoneBook::confirm_to_del_oldest(){
	std::cout
		<< YELLOW << "The phonebook is full.\nThe oldest contact is:\n" << RESET
		<< "First name: " << contact[oldest_index].get_first_name() << "\n"
		<< "Last name:  " << contact[oldest_index].get_last_name() << "\n"
		<< "Nickname:   " << contact[oldest_index].get_nickname() << "\n"
		<< YELLOW << "Adding a new contact will overwrite this one." << RESET
		<< std::endl;
	std::string	input;
	while (1){
		std::cout << CYAN << "Do you want to proceed? (y/n): " << RESET;
		w_getline(input);
		if (input == "y" || input == "Y" || input == "yes" || input == "YES")
			return true;
		else if (input == "n" || input == "N" || input == "no" || input == "NO"){
			std::cout
				<< YELLOW
				<< "Operation cancelled. The new contact was not added."
				<< RESET << std::endl;
			return false;
		}else{
			std::cout
				<< RED << "Invalid input. Please enter 'y' or 'n'."
				<< RESET << std::endl;
		}
	}
}

void	PhoneBook::add_contact(){
	std::string input;
	Contact temp;
	get_valid_input_char("? First name:     ", input);
	temp.set_first_name(input);
	get_valid_input_char("? Last name:      ", input);
	temp.set_last_name(input);
	get_valid_input_char("? Nickname:       ", input);
	temp.set_nickname(input);
	get_valid_input_num("? Phone number:   ", input);
	temp.set_phone_num(input);
	get_valid_input_char("? Darkest secret: ", input);
	temp.set_secret(input);
	if (contact_count == 8){
		if (!confirm_to_del_oldest())
			return ;
		contact[oldest_index] = temp;
		if (oldest_index == 7)
			oldest_index = 0;
		else
			oldest_index++;
	}else{
		contact[contact_count] = temp;
		contact_count++;
	}
	std::cout
		<< GREEN << "Contact successfully added."
		<< RESET << std::endl;
}

int	PhoneBook::get_actual_index(int index){
	int	actual_index;

	if (oldest_index + index < 8)
		actual_index = oldest_index + index;
	else
		actual_index = (oldest_index + index) % 8;
	return actual_index;
}

void	PhoneBook::format_column(const std::string& str){
	if (str.length() > 10)
		std::cout << std::setw(9) << std::right << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << std::right << str;
}

void	PhoneBook::print_raw(
			const std::string& index, const std::string& first_name,
			const std::string& last_name, const std::string& nickname){
	std::cout << "|";
	format_column(index);
	std::cout << "|";
	format_column(first_name);
	std::cout << "|";
	format_column(last_name);
	std::cout << "|";
	format_column(nickname);
	std::cout << "|" << std::endl;
}

void	PhoneBook::print_phonebook(){
	std::cout << BOLD;
	print_raw("Index", "First name", "Last name", "Nickname");
	std::cout << RESET;
	for (int i = 0; i < contact_count; ++i){
		std::ostringstream ss;
		ss << i;
		int actual_index;
		actual_index = get_actual_index(i);
		print_raw(std::string(ss.str()),
			contact[actual_index].get_first_name(),
			contact[actual_index].get_last_name(),
			contact[actual_index].get_nickname());
	}
}

int	PhoneBook::get_index(){
	while (1){
		std::cout << CYAN << "Please enter the index of the contact: " << RESET;
		std::string input;
		w_getline(input);
		if (input.empty())
			continue ;
		else{
			std::stringstream ss(input);
			int index;
			if (ss >> index && ss.eof()
				&& index >= 0 && index <= contact_count - 1)
				return index;
			else{
				std::cout << RED << "Invalid index. Please enter a number ";
				if (contact_count == 1)
					std::cout << "(0)";
				else
					std::cout << "(0-" << contact_count - 1 << ")";
				std::cout << "." << RESET << std::endl;
				continue ;
			}
		}
	}
}

void	PhoneBook::print_contact(int index){
	int	actual_index = get_actual_index(index);
	std::cout
		<< BOLD << "First name:     " << RESET
		<< contact[actual_index].get_first_name() << "\n"
		<< BOLD << "Last name:      " << RESET
		<< contact[actual_index].get_last_name() << "\n"
		<< BOLD << "Nickname:       " << RESET
		<< contact[actual_index].get_nickname() << "\n"
		<< BOLD << "Phone number:   " << RESET
		<< contact[actual_index].get_phone_num() << "\n"
		<< BOLD << "Darkest secret: " << RESET
		<< contact[actual_index].get_secret() << std::endl;
}

void	PhoneBook::search_contact(){
	if (contact_count == 0){
		std::cout << YELLOW << "Phonebook is empty." << RESET << std::endl;
		return ;
	}
	print_phonebook();
	print_contact(get_index());
}
