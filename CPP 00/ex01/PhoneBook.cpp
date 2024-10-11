/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:41:58 by daortega          #+#    #+#             */
/*   Updated: 2024/10/11 15:01:25 by daortega         ###   ########.fr       */
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
	std::cout << "  index   " << "|" << "first name" << "|" << "last name " << "|" << "nickname  " << std::endl;
	for (int i = 0; i < n_contacts && i < 8; i++)
	{
		_contacts[i].printContact(i + 1);
	}
	
}