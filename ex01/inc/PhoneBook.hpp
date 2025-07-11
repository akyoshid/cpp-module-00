/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:42:35 by akyoshid          #+#    #+#             */
/*   Updated: 2025/07/11 16:42:30 by akyoshid         ###   ########.fr       */
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
		void		search_contact() const;
	private:
		Contact		contact[8];
		int			contact_count;
		int			oldest_index;
		static bool	check_available_char_set(const std::string& input);
		static bool	check_available_num_set(const std::string& input);
		static bool	check_blank(const std::string& input);
		static void	get_valid_input_char(
						const std::string& prompt, std::string& input);
		static void	get_valid_input_num(
						const std::string& prompt, std::string& input);
		bool		confirm_to_del_oldest() const;
		int			get_actual_index(int index) const;
		static void	format_column(const std::string& str);
		static void	print_raw(const std::string& index,
						const std::string& first_name,
						const std::string& last_name,
						const std::string& nickname);
		void		print_phonebook() const;
		int			get_index() const;
		void		print_contact(int index) const;
};

#endif
