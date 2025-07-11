/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akyoshid <akyoshid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 19:05:29 by akyoshid          #+#    #+#             */
/*   Updated: 2025/07/11 16:42:37 by akyoshid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>

class	Contact{
	public:
		Contact();
		~Contact();
		void		set_first_name(const std::string& s);
		void		set_last_name(const std::string& s);
		void		set_nickname(const std::string& s);
		void		set_phone_num(const std::string& s);
		void		set_secret(const std::string &s);
		std::string	get_first_name() const;
		std::string	get_last_name() const;
		std::string	get_nickname() const;
		std::string	get_phone_num() const;
		std::string	get_secret() const;
	private:
		std::string	first_name;
		std::string	last_name;
		std::string nickname;
		std::string	phone_num;
		std::string	secret;
};

#endif
