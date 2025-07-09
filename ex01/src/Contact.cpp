/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:05:20 by akyoshid          #+#    #+#             */
/*   Updated: 2025/07/09 14:45:04 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

Contact::Contact(){
}

Contact::~Contact(){
}

void	Contact::set_first_name(const std::string& s){
	first_name = s;
}

void	Contact::set_last_name(const std::string& s){
	last_name = s;
}

void	Contact::set_nickname(const std::string& s){
	nickname = s;
}

void	Contact::set_phone_num(const std::string& s){
	phone_num = s;
}

void	Contact::set_secret(const std::string& s){
	secret = s;
}

std::string	Contact::get_first_name(){
	return first_name;
}

std::string	Contact::get_last_name(){
	return last_name;
}

std::string	Contact::get_nickname(){
	return nickname;
}

std::string	Contact::get_phone_num(){
	return phone_num;
}

std::string	Contact::get_secret(){
	return secret;
}
