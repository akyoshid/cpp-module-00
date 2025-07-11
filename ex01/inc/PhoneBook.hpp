/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:42:35 by akyoshid          #+#    #+#             */
/*   Updated: 2025/07/11 15:16:41 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <iomanip>
# include "Contact.hpp"
# include "utils.hpp"
# include "colors.hpp"

class	PhoneBook{
	public:
		PhoneBook();
		~PhoneBook();
		void		add_contact();
		void		search_contact();
	private:
		Contact		contact[8];
		int			contact_count;
		int			oldest_index;
		bool		check_available_char_set(std::string& input);
		bool		check_available_num_set(std::string& input);
		bool 		check_blank(std::string& input);
		void		get_valid_input_char(
						std::string prompt, std::string& input);
		void		get_valid_input_num(
						std::string prompt, std::string& input);
		bool		confirm_to_del_oldest();
		int			get_actual_index(int index);
		void		format_column(const std::string& str);
		void		print_raw(const std::string& index,
						const std::string& first_name,
						const std::string& last_name,
						const std::string& nickname);
		void		print_phonebook();
		int			get_index();
		void		print_contact(int index);
};

#endif
