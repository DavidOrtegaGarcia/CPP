/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:41:58 by daortega          #+#    #+#             */
/*   Updated: 2024/10/14 16:43:54 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	n_contacts = 0;
	std::cout << "Default constructor PhoneBook called" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Default destructor PhoneBook called" << std::endl;
}
void PhoneBook::add()
{
	_contacts[n_contacts%8].addContact();
	n_contacts++;
}
void PhoneBook::search()
{
	std::string contact_index;
	
	// INDEX
	std::cout << "     Index|" << "First Name|" << " Last Name|" << "  Nickname" << std::endl;
	for (int i = 0; i < n_contacts && i < 8; i++)
		_contacts[i].printContact(i + 1);

	std::cout << "Write the index of the contact you want to watch: "; 
	getline(std::cin, contact_index);
	if (std::cin.eof())
		exit(1);
	if (contact_index.size() != 1 || contact_index[0] < '1' || contact_index[0] > '8') 
		std::cout << "That contact doesn't exist " << std::endl;
	else{
		int index = atoi(contact_index.c_str());
		if (index > n_contacts)
			std::cout << "That contact doesn't exist " << std::endl;
		else
			_contacts[index - 1].printFullContact();
	}
}