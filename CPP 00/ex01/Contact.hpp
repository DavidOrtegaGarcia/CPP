/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:56:53 by daortega          #+#    #+#             */
/*   Updated: 2024/10/14 16:34:43 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <cstring>
# include <cstdlib> 

class Contact
{
private:
	std::string _fname;
	std::string _lname;
	std::string _nick;
	std::string _phone;
	std::string _darkest_secret;

public:
	Contact();
	~Contact();
	void setFname(std::string fname);
	void setLname(std::string lname);
	void setNick(std::string nick);
	void setPhone(std::string phone);
	void setDarkestSecret(std::string darkest_secret);
	void addContact();
	void printContact(int index);
	void printFullContact();
};

#endif