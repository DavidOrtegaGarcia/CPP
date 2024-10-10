/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:41:58 by daortega          #+#    #+#             */
/*   Updated: 2024/10/10 16:10:18 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	i = 0;
	std::cout << "Default constructor PhoneBook called" << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "Default destructor PhoneBook called" << std::endl;
}
void PhoneBook::add()
{
	_contacts[i%8].addContact();
	i++;
}
void PhoneBook::search()
{
	for (int i = 0; i < 8; i++)
	{
		_contacts[i].printContact();
	}
	
}